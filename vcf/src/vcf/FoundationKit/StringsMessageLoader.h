#ifndef _VCF_STRINGSMESSAGELOADER_H__
#define _VCF_STRINGSMESSAGELOADER_H__


#ifndef _VCF_MESSAGELOADER_H__
#	include "vcf/FoundationKit/MessageLoader.h"
#endif // _VCF_MESSAGELOADER_H__

namespace VCF {
 

class FRAMEWORK_API StringsMessageLoader : public MessageLoader {
public:

	class FRAMEWORK_API Exception : public BasicException {
	public:
		Exception( const String& message, int line, int col ): 
		  BasicException( message + StringUtils::format( "\nError occurred on line %d, column %d.", line, col ) ) {	}
	};

	StringsMessageLoader();

	virtual ~StringsMessageLoader();

	virtual void loadMessageFile( const UnicodeString& fileName );

	virtual UnicodeString getMessageFromID( const UnicodeString& id );

	
protected:
	enum ParseState{
		psToken,
		psComment,
		psKey,
		psAssignment,
		psValue,
		psEscapeSequence
	};

	typedef std::pair<UnicodeString,UnicodeString> KeyValPair;
	typedef std::map<UnicodeString,UnicodeString> KeyValMap;

	typedef std::map<UnicodeString,KeyValMap*> TranslationMap;

	TranslationMap translationTable_;
	ParseState parseState_;
	UnicodeString currentTableName_;

	void processEscapeSequence( UnicodeString& escapeSeqString, UnicodeString& tokenString );
};


};


#endif // _VCF_STRINGSMESSAGELOADER_H__


