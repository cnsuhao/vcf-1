//Strings.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

namespace VCF { 

class Formatter {
public:
	
	Formatter( const String& fmtStr ): fmtStr_(fmtStr),currentPos_(0),
										expectedFormatArgCount_(0), currentFormatArgCount_(0){
		
		expectedFormatArgCount_ = countFormatTokens();

		currentPos_ = fmtStr_.find( "%" );
		if ( String::npos == currentPos_ ) {
			output_ += fmtStr_;
			fmtStr_.resize(0);
		}
	}

	//should we add virtual here for customizing the class???
	~Formatter() {
		//assert if the % operator wasn't called the correct number of times
		VCF_ASSERT ( currentFormatArgCount_ < expectedFormatArgCount_ );
	}
	
	template<typename ValType>
	Formatter& operator% ( const ValType& val ) {
		currentFormatArgCount_  ++;

		VCF_ASSERT ( currentFormatArgCount_ <= expectedFormatArgCount_ );
		if ( currentFormatArgCount_ > expectedFormatArgCount_ ) {
			return *this;
		}

		if ( !fmtStr_.empty() ) {  
			if ( String::npos != currentPos_ ) {
				//look ahead and see if we have two consecutive %% chars
				//if so treat as one %
				if ( (fmtStr_.size() >= (currentPos_+1)) && (fmtStr_[currentPos_+1] == '%') ) {
					output_ += fmtStr_.substr(0, currentPos_ ); //just copy off the first "%" char
					fmtStr_.erase( 0, currentPos_+1 );//erase up the 2nd "%" pos
				}
				else { //we have to format this string
					int endPos = getNextFormatTokenEndPos( currentPos_ );
					
					output_ += fmtStr_.substr( 0, currentPos_ );
					fmtStr_.erase( 0, currentPos_ );
					String fmt;

					if ( String::npos != endPos ) {												
						fmt = fmtStr_.substr( 0, endPos-currentPos_ );			
						
						fmtStr_.erase( 0, endPos-currentPos_ );
					}
					else{
						fmt = fmtStr_;						
						fmtStr_.resize(0);
					}

					char tmp[256];
					sprintf( tmp, fmt.ansi_c_str(), val );
					output_ += tmp;
				}
			}
			else {
				output_ += fmtStr_;
				fmtStr_.resize(0);
			}
			
			currentPos_ = fmtStr_.find( "%" );
			if ( String::npos == currentPos_ ) {
				output_ += fmtStr_;
				fmtStr_.resize(0);
			}
		}		
		return *this;
	}
	
	
	
	operator String() const {
		return output_;
	}
protected:
	int countFormatTokens() const {
		int result = 0;
		String searchToken = "%";
		int pos = fmtStr_.find( searchToken );

		while ( pos != String::npos ) {
			if ( !( (fmtStr_.size() >= (pos+1)) && (fmtStr_[pos+1] == '%') ) ) {
				result ++;
			}
			pos = fmtStr_.find( searchToken, pos+1);
		}

		return result;
	}

	int getNextFormatTokenEndPos( int startPos ) const {  
		
		int result = String::npos;
		
		if ( fmtStr_[startPos] != '%' ) {
			return result;
		}
		
		
		//flags: "-+0 #"
		
		//width [1..9,0]*
		
		//precision ".[1..9,0]"
		
		//precision for int? "hlI64L"
		
		//type "cCdiouxXeEfgnpsS"
		
		
		String search = "-+0 #123456789*.hlI64LcCdiouxXeEfgnpsS";
		
		result = fmtStr_.find_first_not_of( search, startPos+1 );
		
		return result;
	}
private:
	String fmtStr_;
	int currentPos_;
	String output_;
	int expectedFormatArgCount_;
	int currentFormatArgCount_;
};


};



/**
Sample object that demonstrates overloading the toString method of the 
Object base class.
*/
class Foo : public VCF::Object {
public:
	virtual VCF::String toString() {
		return "Foo here!\n\t" + Object::toString();
	}
};


/**
*use the VCF namespace to make it more convenient
*to refer to VCF classes
*/
using namespace VCF;


/**
This example show how to work with strings
in the VCF and some of the extra utility functions in the StringUtils class.
Many thanks to Cesar Mello for doing the initial work on this
*/
int main(int argc, char *argv[])
{
	FoundationKit::init( argc, argv );

	try { 
		// creating strings
		String s = "Now";
		String t = s + " is the time."; // concatenate strings with + operator

		/**
		use System::println() to send the String to stdout
		*/
		System::println(t);

		int len = t.size();  // number of characters: 16
		System::println("Number of characters: %d", len);

		String sub = t.substr(4); // returns char 4 to end: "is the time."
		System::println("substr(4): " + sub);

		sub = t.substr(4, 2); // returns chars 4 and 5
		System::println("substr(4, 2): " + sub);

		String toFind = "foo";
		int pos = t.find(toFind); // does not find the string (returns String::npos)

		if (pos == UnicodeString::npos)
		{
			System::println( "trying to find string \"foo\": not found. returns String::npos: %d", pos);
		}

		System::println( toFind );

		toFind = "time";

		System::println( toFind );

		pos = t.find("time"); // finds the string "time" in position 11
		System::println("string \"time\" found at position: %d in string {%ls}", pos, t.c_str() );


		

		Foo f;
		System::println( "f is: " + f + "\n" + 99.5643231 + " bottles of " + &f + " on the wall!" );

		System::println( String("Is this ") + true + " or is this " + false + "?" );

		DateTime dt = DateTime::now();

		System::println( "The time is now: " + dt );

		void* ptr = &dt;

		System::println( String("The value of the void* pointer ptr is: ") + ptr );


		int i;
		bool j;
		const double* k;
		float l;
		Object o;
		
		System::println( "i is a " + typeid(i) + " type" );
		System::println( "j is a " + typeid(j) + " type" );
		System::println( "k is a " + typeid(k) + " type" );
		System::println( "l is a " + typeid(l) + " type" );
		System::println( "o is a " + typeid(o) + " type" );
		System::println( "f is a " + typeid(f) + " type" );
		System::println( "ptr is a " + typeid(ptr) + " type" );
		System::println( "dt is a " + typeid(dt) + " type" );

		long64 m = 0xffffffff;
		System::println( String("m: ") + m );

		m *= -0xfff;

		System::println( String("m: ") + m );


		VariantData v;
		v = 123;

		System::println( String("Variant (as int): ") + v );

		v = 441.2340995;
		System::println( String("Variant (as double): ") + v );

		v = &f;
		System::println( String("Variant (as object): ") + v );

		v = &dt;
		System::println( String("Variant (as object): ") + v );

		v = true;
		System::println( String("Variant (as boolean): ") + v );

		v = -199;
		System::println( String("Variant (as signed int): ") + v );

		v = 'A';
		System::println( String("Variant (as character): ") + v );

		v = "Hello World!";
		System::println( String("Variant (as string): ") + v );

		/**
		String utility functions
		*/

		/**
		format a string
		*/		
		String formattedString = Formatter( "hello %d, %0.2f World!!" ) % 1002 % 12.456330;
		System::println( formattedString );

		//error - too many arguments, expecting 2 argument, recv'd 3!
		try {
			formattedString = Formatter( "hello %d, %0.2f World!!" ) % 1002 % 0.0786 % 456;
			System::println( formattedString );
		}
		catch ( std::exception& e ) {
			printf( "%s\n", e.what() );
		}



		//StringUtils::format is deprecated - don't use in new code
		formattedString = StringUtils::format( "Number: %d, as hex: 0x%08X, a string: %ls", 12, 12, toFind.c_str() );
		System::println( formattedString );


		//same thing with a Formatter
		formattedString = Formatter( "Number: %d, as hex: 0x%08X, a string: %ls") % 12 % 12 % toFind.c_str();
		System::println( formattedString );

		
		/**
		getting a class name from type info
		*/

		String className = StringUtils::getClassNameFromTypeInfo( typeid(double) );

		System::println( "StringUtils::getClassNameFromTypeInfo() returned: %ls", className.c_str() );

		className = StringUtils::getClassNameFromTypeInfo( typeid(StringUtils) );
		System::println( "StringUtils::getClassNameFromTypeInfo() returned: %ls", className.c_str() );

		className = StringUtils::getClassNameFromTypeInfo( typeid(System) );
		System::println( "StringUtils::getClassNameFromTypeInfo() returned: %ls", className.c_str() );



		/**
		transform a string to and from upper case and lowercase
		*/

		String xfrmedString = StringUtils::lowerCase( className );

		System::println( "lowercase: %ls", xfrmedString.c_str() );

		xfrmedString = StringUtils::upperCase( className );

		System::println( "uppercase: %ls", xfrmedString.c_str() );


		/**
		This will generate a new UUID and return it as a string
		*/
		String newUUID = StringUtils::newUUID();

		System::println( "new UUID: %ls", newUUID.c_str() );


		/**
		converts various non string types to a string
		*/

		String val = StringUtils::toString( 12 );
		System::println( "value: %ls", val.c_str() );

		val = StringUtils::toString( 1234.009459034 );
		System::println( "value: %ls", val.c_str() );

		val = StringUtils::toString( 53433.000034f );
		System::println( "value: %ls", val.c_str() );

		val = StringUtils::toString( true );
		System::println( "value: %ls", val.c_str() );

		val = StringUtils::toString( false );
		System::println( "value: %ls", val.c_str() );


		/**
		A trace statement useful for debugging. On Win32 systems this goes to the
		debugger for the current application
		*/

		StringUtils::trace( "Hello World" );

		/**
		Same as above, only with variable arguments
		*/
		StringUtils::traceWithArgs( "Hello World %d times", 10 );


		/**
		This demonstrates trimming text from a string
		*/
		String original = "####Some text#######";

		xfrmedString = StringUtils::trim( original, '#' );
		System::println( "original: %ls \nxfrmedString after StringUtils::trim(): %ls", original.c_str(), xfrmedString.c_str() );


		xfrmedString = StringUtils::trimLeft( original, '#' );
		System::println( "original: %ls \nxfrmedString after StringUtils::trimLeft(): %ls", original.c_str(), xfrmedString.c_str() );

		xfrmedString = StringUtils::trimRight( original, '#' );
		System::println( "original: %ls \nxfrmedString after StringUtils::trimRight(): %ls", original.c_str(), xfrmedString.c_str() );


		/**
		The next examples uses the white space trimming functions
		*/

		original = "   12333873   ";

		xfrmedString = original;
		StringUtils::trimWhiteSpaces( xfrmedString );
		System::println( "original: \"%ls\"\nxfrmedString after StringUtils::trimWhiteSpaces(): %ls", original.c_str(), xfrmedString.c_str() );

		xfrmedString = original;
		StringUtils::trimWhiteSpacesLeft( xfrmedString );
		System::println( "original: \"%ls\"\nxfrmedString after StringUtils::trimWhiteSpacesLeft(): \"%ls\"", original.c_str(), xfrmedString.c_str() );


		xfrmedString = original;
		StringUtils::trimWhiteSpacesRight( xfrmedString );
		System::println( "original: \"%ls\"\nxfrmedString after StringUtils::trimWhiteSpacesRight(): \"%ls\"", original.c_str(), xfrmedString.c_str() );
	}
	catch ( std::exception& e ) {
		printf( e.what() );
	}


	FoundationKit::terminate();

	return 0;
}













namespace VCF {




};


/**
*CVS Log info
*$Log$
*Revision 1.3.4.2  2005/03/06 22:50:57  ddiego
*overhaul of RTTI macros. this includes changes to various examples to accommadate the new changes.
*
*Revision 1.3.4.1  2005/02/16 05:09:30  ddiego
*bunch o bug fixes and enhancements to the property editor and treelist control.
*
*Revision 1.3  2004/08/07 02:47:38  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.2.4.9  2004/06/06 07:05:27  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.2.4.7  2004/05/31 13:20:56  ddiego
*more osx updates
*
*Revision 1.2.4.6  2004/05/03 03:44:52  ddiego
*This checks in a bunch of changes to the FoundationKit for OSX
*porting. The thread, mutex, semaphor, condition, and file peers
*have all been implemented and tested. The file peer could be improved
*and needs search functionality. The locale peer is only partially
*complete, but the functions will return values. The unicode transition
*is also finished and works OK now.
*
*Revision 1.2.4.5  2004/04/29 03:40:57  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


