//Socket.cpp

#include "vcf/NetworkKit/NetworkKit.h"
#include "vcf/NetworkKit/Socket.h"
#include "vcf/NetworkKit/NetworkToolkit.h"
#include "vcf/FoundationKit/Dictionary.h"


const VCF::String VCF::Socket::soBlocking = "soBlocking"; 
const VCF::String VCF::Socket::soBroadcast = "soBroadcast";
const VCF::String VCF::Socket::soDontLinger = "soDontLinger";
const VCF::String VCF::Socket::soDontRoute = "soDontRoute";
const VCF::String VCF::Socket::soKeepAlive = "soKeepAlive";
const VCF::String VCF::Socket::soRecvBuffer = "soRecvBuffer";
const VCF::String VCF::Socket::soReuseAddress = "soReuseAddress";
const VCF::String VCF::Socket::soSendBuffer = "soSendBuffer";



using namespace VCF;



Socket::Socket():
	peer_(NULL),
	type_(Socket::stStream),
	state_(0)
{
	peer_ = NetworkToolkit::createSocketPeer(type_);

	if ( NULL == peer_ ) {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create socket peer.") );
	}

	peer_->setPeerOwner( this );

	if ( 0 != peer_->create() ) {
		throw RuntimeException( MAKE_ERROR_MSG_2("Peer failed to create socket instance.") );
	}
}


Socket::Socket(const SocketType& socketType):
	peer_(NULL),
	type_(socketType),
	state_(0)
{
	peer_ = NetworkToolkit::createSocketPeer(type_);

	if ( NULL == peer_ ) {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create socket peer.") );
	}

	peer_->setPeerOwner( this );

	if ( 0 != peer_->create() ) {
		throw RuntimeException( MAKE_ERROR_MSG_2("Peer failed to create socket instance.") );
	}
}

Socket::Socket( unsigned short port ):
	peer_(NULL),
	type_(Socket::stStream),
	state_(0)
{
	peer_ = NetworkToolkit::createSocketPeer(type_);

	if ( NULL == peer_ ) {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create socket peer.") );
	}

	peer_->setPeerOwner( this );

	open();

	listen( port );
}

Socket::Socket( const String& host, unsigned short port ):
	peer_(NULL),
	type_(Socket::stStream),
	state_(0)
{
	peer_ = NetworkToolkit::createSocketPeer(type_);
	
	if ( NULL == peer_ ) {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create socket peer.") );
	}

	peer_->setPeerOwner( this );

	open();

	connect( host, port );
}

Socket::Socket( SocketPeer* peer ):
	peer_(peer),
	type_(Socket::stStream),
	state_(0)
{
	if ( NULL == peer_ ) {
		throw InvalidPeer( MAKE_ERROR_MSG_2("NULL peer instance passed in to Socket constructor.") );
	}

	peer_->setPeerOwner( this );
}

Socket::~Socket()
{
	close();
	peer_->setPeerOwner( NULL );
	delete peer_;
}

void Socket::open()
{
	close();
	
	if ( 0 != peer_->create() ) {
		throw RuntimeException( MAKE_ERROR_MSG_2("Peer failed to create socket instance.") );
	}

	state_ = Socket::ssOpen;
}

void Socket::close()
{
	state_ = Socket::ssClosed;
	if ( 0 != peer_->close() ) {
		throw RuntimeException( MAKE_ERROR_MSG_2("Attempt to close peer failed.") );
	}
}

void Socket::connect( const String& host, unsigned short port )
{
	if ( 0 != peer_->connect( host, port ) ) {
		state_ &= ~Socket::ssConnected;
		throw SocketException( MAKE_ERROR_MSG_2(Format("Peer failed connect to '%s', port %d.") % host % port) );
	}

	state_ |= Socket::ssConnected;
}

void Socket::listen( unsigned short port )
{
	if ( 0 != peer_->listen( port ) ) {
		state_ &= ~Socket::ssListening;
		throw SocketException( MAKE_ERROR_MSG_2(Format("Peer failed listen on port %d.") % port ) );
	}

	state_ |= Socket::ssListening;
}

void Socket::selectFor( uint32 timeout, uint32 flags )
{
	VCF_ASSERT( flags != 0 );

	if ( 0 == flags ) {
		return;
	}

	SocketArray* readArrPtr = NULL;
	SocketArray* writeArrPtr = NULL;
	SocketArray* errorArrPtr = NULL;

	SocketArray readArr(1);
	readArr[0] = this;
	SocketArray writeArr(1);
	writeArr[0] = this;
	SocketArray errorArr(1);
	errorArr[0] = this;

	if ( flags & Socket::ssReadable ) {
		readArrPtr = &readArr;
	}

	if ( flags & Socket::ssWriteable ) {
		writeArrPtr = &writeArr;
	}

	if ( flags & Socket::ssError ) {
		errorArrPtr = &errorArr;
	}
	
	getPeer()->select( timeout, readArrPtr, writeArrPtr, errorArrPtr );
}

TCPSocket* Socket::accept()
{
	TCPSocket* result = NULL;

	SocketPeer* newSockPeer = peer_->accept();
	if ( NULL != newSockPeer ) {
		result = new TCPSocket( newSockPeer );

		SocketEvent e(this,Socket::seClientConnected);
		e.socket = result;
		ClientConnected( &e );
	}

	return result;
}

bool Socket::validateOptions( Dictionary& options )
{
	bool result = true;

	Dictionary::Enumerator* enumerator = options.getEnumerator();

	static std::map<String,String> validOptionTypes;
	if ( validOptionTypes.empty() ) {
		validOptionTypes[Socket::soBlocking] = Socket::soBlocking;
		validOptionTypes[Socket::soBroadcast] = Socket::soBroadcast;
		validOptionTypes[Socket::soDontLinger] = Socket::soDontLinger;
		validOptionTypes[Socket::soDontRoute] = Socket::soDontRoute;
		validOptionTypes[Socket::soKeepAlive] = Socket::soKeepAlive;
		validOptionTypes[Socket::soRecvBuffer] = Socket::soRecvBuffer;
		validOptionTypes[Socket::soReuseAddress] = Socket::soReuseAddress;
		validOptionTypes[Socket::soSendBuffer] = Socket::soSendBuffer;
	}


	while ( enumerator->hasMoreElements() ) {
		Dictionary::pair element = enumerator->nextElement();
		if ( validOptionTypes.find( element.first ) == validOptionTypes.end() ) {
			result = false;
			break;	
		}
	}

	return result;
}


void Socket::setOptions( Dictionary& options )
{
	if ( Socket::validateOptions( options ) ) {
		peer_->setOptions( options );
	}
	else {
		throw RuntimeException( MAKE_ERROR_MSG_2("Invalid option (or options) passed to socket - no options set.") );
	}
}

Dictionary Socket::getOptions()
{
	return peer_->getOptions();
}

IPAddress Socket::getLocalHostIPAddress()
{
	return peer_->getLocalHostIPAddress();
}

unsigned short Socket::getLocalPort()
{
	return peer_->getLocalPort();
}


IPAddress Socket::getRemoteHostIPAddress()
{
	return peer_->getRemoteHostIPAddress();
}

unsigned short Socket::getRemotePort()
{
	return peer_->getRemotePort();
}


bool Socket::pending() 
{
	SocketArray readArr(1);
	readArr[0] = this;
	SocketArray writeArr(1);
	writeArr[0] = this;	
	
	getPeer()->select( Socket::SelectNoWait, &readArr, &writeArr, NULL );

	return isReadable() || isWriteable();
}


bool Socket::wouldOperationBlock()
{
	return peer_->wouldOperationBlock();
}










TCPSocketInputStream::TCPSocketInputStream( TCPSocket& socket ):
	totalBytesRecvd_(0),
	socket_(&socket)
{

}


uint64 TCPSocketInputStream::read( unsigned char* bytesToRead, uint64 sizeOfBytes )
{
	uint64 bytesRead = 0;

	int err = socket_->getPeer()->recv( bytesToRead, sizeOfBytes );
	if ( err >= 0 ) {
		bytesRead = err;
	}
	else if (!socket_->wouldOperationBlock()) { //the operation flat out failed
		throw SocketReadException( MAKE_ERROR_MSG_2("Socket peer's recv() failed.") );
	}
	
	totalBytesRecvd_ += bytesRead;

	return bytesRead;
}



TCPSocketOutputStream::TCPSocketOutputStream( TCPSocket& socket ):
	totalBytesWritten_(0),
	socket_(&socket)
{

}

uint64 TCPSocketOutputStream::write( const unsigned char* bytesToWrite, uint64 sizeOfBytes )
{
	uint64 bytesWritten = 0;

	int err = socket_->getPeer()->send( bytesToWrite, sizeOfBytes );

	if ( err >= 0 ) {
		bytesWritten = err;
	}
	else if (!socket_->wouldOperationBlock()) { //the operation flat out failed

		throw SocketWriteException( MAKE_ERROR_MSG_2("Socket peer's send() failed.") );
	}

	totalBytesWritten_ += bytesWritten;

	return bytesWritten;
}











UDPSocketInputStream::UDPSocketInputStream( UDPSocket& socket, const IPEndPoint& readFrom ):
	totalBytesRecvd_(0),
	socket_(&socket),
	readFrom_(readFrom)
{

}


uint64 UDPSocketInputStream::read( unsigned char* bytesToRead, uint64 sizeOfBytes )
{
	return readFrom( bytesToRead, sizeOfBytes, readFrom_ );
}

uint64 UDPSocketInputStream::readFrom( unsigned char* bytesToRead, uint64 sizeOfBytes, IPEndPoint& from )
{
	uint64 bytesRead = 0;

	int err = socket_->getPeer()->recvFrom( bytesToRead, sizeOfBytes, from );
	if ( err >= 0 ) {
		bytesRead = err;
	}
	else if (!socket_->wouldOperationBlock()) { //the operation flat out failed
		throw SocketReadException( MAKE_ERROR_MSG_2("Socket peer's recv() failed.") );
	}
	
	totalBytesRecvd_ += bytesRead;

	return bytesRead;
}



UDPSocketOutputStream::UDPSocketOutputStream( UDPSocket& socket, const IPEndPoint& sendTo ):
	totalBytesWritten_(0),
	socket_(&socket),
	sendTo_(sendTo)
{

}

uint64 UDPSocketOutputStream::write( const unsigned char* bytesToWrite, uint64 sizeOfBytes )
{
	return writeTo( bytesToWrite, sizeOfBytes, sendTo_ );
}

uint64 UDPSocketOutputStream::writeTo( const unsigned char* bytesToWrite, uint64 sizeOfBytes, const IPEndPoint& to )
{
	uint64 bytesWritten = 0;

	int err = socket_->getPeer()->sendTo( bytesToWrite, sizeOfBytes, to );

	if ( err >= 0 ) {
		bytesWritten = err;
	}
	else if (!socket_->wouldOperationBlock()) { //the operation flat out failed

		throw SocketWriteException( MAKE_ERROR_MSG_2("Socket peer's send() failed.") );
	}

	totalBytesWritten_ += bytesWritten;

	return bytesWritten;
}










TCPSocket::TCPSocket():
	Socket(Socket::stStream)
{

}

TCPSocket::TCPSocket( unsigned short port ):
	Socket(Socket::stStream)
{
	listen( port );
}

TCPSocket::TCPSocket( const String& host, unsigned short port ):
	Socket(Socket::stStream)
{
	connect( host, port );
}










UDPSocket::UDPSocket():
	Socket(Socket::stDatagram)
{

}

UDPSocket::UDPSocket( unsigned short port ):
	Socket(Socket::stDatagram)
{

}

UDPSocket::UDPSocket( const String& host, unsigned short port ):
	Socket(Socket::stDatagram)
{

}

void UDPSocket::connect()
{
	Socket::connect( "", 0 );
}