//Win32IPAddressPeer.cpp

#include "NetworkKit.h"
#include "Win32IPAddressPeer.h"


using namespace VCF;



Win32IPAddressPeer::Win32IPAddressPeer()
{
	
}

Win32IPAddressPeer::~Win32IPAddressPeer()
{

}

void Win32IPAddressPeer::initWithHostName( const String& host )
{
	host_ = host;
}

void Win32IPAddressPeer::initWithIPAddr( const IPAddress::RawBytes& ipAddr )
{
	struct in_addr addr;
	memset( &addr,0,sizeof(addr) );
	addr.S_un.S_un_b.s_b1 = ipAddr[0];
	addr.S_un.S_un_b.s_b2 = ipAddr[1];
	addr.S_un.S_un_b.s_b3 = ipAddr[2];
	addr.S_un.S_un_b.s_b4 = ipAddr[3];

	ipAddress_ = inet_ntoa(addr);
}

void Win32IPAddressPeer::initAsLocalHost()
{
	host_ = "localhost";
}

IPAddress::RawBytes Win32IPAddressPeer::getAddressBytes()
{
	IPAddress::RawBytes result(4);

	struct in_addr addr;

	if ( ipAddress_.empty() ) {
		
		memset( &addr,0,sizeof(addr) );

		hostent* host = gethostbyname( host_.c_str() );
		if ( NULL != host ) {
			memcpy( &(addr.s_addr), host->h_addr, host->h_length );
		}
		else {
			throw NetworkException("Unable to determine host information from address: " + host_ );
		}
		ipAddress_ = inet_ntoa(addr);
	}
	else {
		addr.S_un.S_addr = inet_addr( ipAddress_.c_str() );
	}
	
	result[0] = addr.S_un.S_un_b.s_b1;
	result[1] = addr.S_un.S_un_b.s_b2;
	result[2] = addr.S_un.S_un_b.s_b3;
	result[3] = addr.S_un.S_un_b.s_b4;

	return result;
}

String Win32IPAddressPeer::getHostName()
{
	String result;

	
	struct in_addr addr;
	memset( &addr,0,sizeof(addr) );


	if ( !ipAddress_.empty() ) {
		addr.S_un.S_addr = inet_addr( ipAddress_.c_str() );	
		

		hostent* host = gethostbyaddr( (const char*)&addr.S_un, sizeof(addr.S_un), 0 );		
		if ( NULL != host ) {
			host_ = host->h_name;
		}
		else {
			throw NetworkException("Unable to determine host information from address: " + ipAddress_ );
		}
	}
	else if ( !host_.empty() ) {
		hostent* host = gethostbyname( host_.c_str() );
		if ( NULL != host ) {
			host_ = host->h_name;
			
			memcpy( &(addr.s_addr), host->h_addr, host->h_length );
			ipAddress_ = inet_ntoa(addr);
		}
		else {
			throw NetworkException("Unable to determine host information from address: " + host_ );
		}
	}

	
	

	result = host_;
	

	return result;
}

String Win32IPAddressPeer::getHostAddress()
{
	String result;

	
	struct in_addr addr;
	memset( &addr,0,sizeof(addr) );
	
	hostent* host = gethostbyname( host_.c_str() );
	if ( NULL != host ) {
		memcpy( &(addr.s_addr), host->h_addr, host->h_length );
		
		if ( host->h_name != host_ ) {
			host_ = host->h_name;
		}
	}
	else {
		throw NetworkException("Unable to determine host information from address: " + host_ );
	}
	ipAddress_ = inet_ntoa(addr);
	
	
	result = ipAddress_;

	return result;
}

bool Win32IPAddressPeer::isIPV4()
{
	return true;
}

bool Win32IPAddressPeer::isIPV6()
{
	return false;
}

