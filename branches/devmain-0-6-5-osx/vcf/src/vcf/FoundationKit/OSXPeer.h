#ifndef _VCF_OSXPEER_H__
#define _VCF_OSXPEER_H__
//OSXPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


namespace VCF {

	class OSXUtils {
	public:
		static String getErrorString( int errorCode );
	};




#define vcf_IntToFixed(a)	   ((Fixed)(a) << 16)
#define vcf_FixedToInt(a)	   ((int)(a) >> 16)

class FixedPointNumber {
public:
	FixedPointNumber() : val_(0){
	}

	FixedPointNumber( Fixed val ) : val_(val){}

	FixedPointNumber( const double val ) {
		*this = val;
	}

	FixedPointNumber& operator=( Fixed rhs ) {
		val_ = rhs;
		return *this;
	}

	FixedPointNumber& operator=( const double& rhs ) {
		assign ( rhs );
		return *this;
	}

	FixedPointNumber& operator=( const float& rhs ) {
		assign ( rhs );
		return *this;
	}

	void assign( const double& val ) {
		int fractional = (val - floor(val)) * 0xffff;

		val_ = vcf_IntToFixed((int)(floor(val))) | fractional;
	}

	void assign( const int& val ) {
		val_ = vcf_IntToFixed(val);
	}

	int asInt() const {
		return vcf_FixedToInt(val_);
	}

	double asDouble() const {
		if ( 0 == val_ ) {
			return 0.0;
		}
		return (double)vcf_FixedToInt(val_) + ((double)(0xFFFF)/(double)(0xFFFF0000 & val_));
	}

	operator double () const {
		return asDouble();
	}

	operator Fixed () const {
		return val_;
	}
protected:
	Fixed val_;
};



class CFTextString {
public:
	CFTextString() : cfStringRef(nil), unicodeText(NULL){

	}

	CFTextString( const String& s ) : cfStringRef(nil), unicodeText(NULL){
		assign( s );
	}

    CFTextString( CFStringRef s ) : cfStringRef(nil), unicodeText(NULL){
		assign( s );
	}

	~CFTextString() {
		cleanup();
	}

	CFTextString& operator=( const String& s ) {
		assign( s );
		return *this;
	}

    CFTextString& operator=( CFStringRef s ) {
		assign( s );
		return *this;
	}

    CFTextString& operator=( const char* s ) {
        CFStringRef strRef =
            CFStringCreateWithCString( NULL, s, CFStringGetSystemEncoding() );

		assign( strRef );

        CFRelease( strRef );

		return *this;
	}


	int length() const {
		return CFStringGetLength( cfStringRef );
	}

	void assign( const String& s ) {
		cleanup();
        cfStringRef = CFStringCreateMutable( NULL, 0 );
		CFStringAppendCharacters( cfStringRef, s.c_str(), s.size() );
		buildUnicodeBuffer();
	}

    void assign( CFStringRef s ) {
		cleanup();

        cfStringRef = CFStringCreateMutableCopy( NULL, 0, s );

		buildUnicodeBuffer();
	}



	CFStringRef ref() const {
		return cfStringRef;
	}

    CFMutableStringRef m_ref() {
		return cfStringRef;
	}

    operator CFMutableStringRef () {
		return cfStringRef;
	}

	operator CFStringRef () const {
		return cfStringRef;
	}

    operator String () const {
        String result = unicodeText;
        return result;
    }

    const char* ansi_c_str() const {
        return CFStringGetCStringPtr( cfStringRef, CFStringGetSystemEncoding() );
    }

	const UniChar* c_str() const {
		return unicodeText;
	}

    void copy( UniChar* buffer, int bufferLength ) const {
        memcpy( buffer, unicodeText, sizeof(UniChar) * bufferLength );
    }

    void formatWithArgs( CFStringRef formatStr, va_list arguments ) {
        CFStringRef strRef = CFStringCreateWithFormatAndArguments( NULL, NULL, formatStr, arguments );

        assign( strRef );

        CFRelease( strRef );
    }


    void format( CFStringRef formatStr, ... ) {
        va_list argList;

        va_start( argList, formatStr );

        formatWithArgs( formatStr, argList );

        va_end( argList );
    }

    void upperCase() {
        CFStringUppercase( cfStringRef, NULL );

        if ( NULL != unicodeText ) {
			delete [] unicodeText;
            unicodeText = NULL;
		}

        buildUnicodeBuffer();
    }

    void lowerCase() {
        CFStringLowercase( cfStringRef, NULL );

        if ( NULL != unicodeText ) {
			delete [] unicodeText;
            unicodeText = NULL;
		}

        buildUnicodeBuffer();
    }
protected:
	void cleanup()	{
		if ( NULL != unicodeText ) {
			delete [] unicodeText;
		}

		if ( nil != cfStringRef ) {
			CFRelease(cfStringRef);
		}
		cfStringRef = nil;
		unicodeText = NULL;
	}

	void buildUnicodeBuffer() {
		int length = CFStringGetLength( cfStringRef );
		unicodeText = new UniChar[length+1];
		CFRange range = {0,length};
		CFStringGetCharacters(cfStringRef,range,unicodeText);
		unicodeText[length] = 0;
	}
	CFMutableStringRef cfStringRef;
	UniChar* unicodeText;

private:
		CFTextString( const CFTextString& rhs );
		CFTextString& operator=( const CFTextString& rhs );
};







};


/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.7.2.1  2004/06/15 04:04:37  ddiego
 *revamped osx theme drawing API
 *
 *Revision 1.1.2.7  2004/06/06 07:05:32  marcelloptr
 *changed macros, text reformatting, copyright sections
 *
 *Revision 1.1.2.5  2004/05/31 19:42:52  ddiego
 *more osx updates
 *
 *Revision 1.1.2.4  2004/05/03 03:44:53  ddiego
 *This checks in a bunch of changes to the FoundationKit for OSX
 *porting. The thread, mutex, semaphor, condition, and file peers
 *have all been implemented and tested. The file peer could be improved
 *and needs search functionality. The locale peer is only partially
 *complete, but the functions will return values. The unicode transition
 *is also finished and works OK now.
 *
 *Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
 *added OSX changes for unicode migration
 *
 *Revision 1.3.2.1  2004/04/26 21:58:43  marcelloptr
 *changes for dir reorganization: _VCF_MACRO_H__
 *
 *Revision 1.3  2004/04/03 15:48:42  ddiego
 *Merged over code from the 0-6-3 branch.
 *
 *Revision 1.2.6.3  2004/02/25 05:17:55  ddiego
 *updates to ApplicationKit to support posting events and timer and idle time handlers for the OSX UI Toolkit.
 *
 *Revision 1.2.6.2  2004/02/24 01:42:43  ddiego
 *initial OSX ApplicationKit port checkin
 *
 *Revision 1.2.6.1  2004/02/21 03:27:06  ddiego
 *updates for OSX porting
 *
 *Revision 1.2  2003/05/17 20:37:12  ddiego
 *this is the checkin for the 0.6.1 release - represents the merge over from
 *the devmain-0-6-0 branch plus a few minor bug fixes
 *
 *Revision 1.1.2.1  2003/05/15 03:01:01  ddiego
 *added initial osx source( FoundationKit only),
 *plus some fixes to compile under GCC 3.x compilers
 *
 */


#endif // _VCF_OSXPEER_H__


