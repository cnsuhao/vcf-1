#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_VCFULONG64_H__
#define _VCF_VCFULONG64_H__

/**
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/


namespace VCF {

/**
This is wrapper class that provides support for an unsigned 64 bit integer.
This ensures that we have a real C++ 64 bit type, as opposed to some weird typedef magic.
For platforms that support a 64bit int we just wrap that. If a platform doesn't support
this, then we would have to add some specialized routines to deal with this. This class
is intended to bu used exactly like you would a long or an int, and support the various
constructors, copy constructors, operator overloads, etc to facilitate this. For example:
<pre>
ulong64 num = 123;
int num2 = num;
num -= 12;
num += 1234444;
num = num / 234;

ulong64 num3(12);
ulong64 num4(num);

if ( num3 == num4 ) { //do something }
</pre>
In addition you can get the high and low 32 bit component via the hi() and lo() methods, 
as in this example:
<pre>
ulong64 num = 0x1234abcd5678cdef;
unsigned long lo = num.lo(); //lo == 0x5678cdef
unsigned long hi = num.hi(); //hi == 0x1234abcd
</pre>
*/

class FRAMEWORK_API ulong64 {
public:

	#ifdef _MSC_VER 
	typedef unsigned __int64 u64_t;
	typedef __int64 int64_t;
#else	
	typedef unsigned long long u64_t;
	typedef long long int64_t;
#endif
	


	ulong64() :data_(0){

	}

	ulong64(u64_t val) :data_(val){

	}

	ulong64(int64_t val) :data_(val){

	}	

	ulong64( unsigned long val ) :data_(val){

	}

	ulong64( unsigned int val ) :data_(val){

	}

	ulong64( unsigned short val ) :data_(val){

	}

	ulong64( unsigned char val ) :data_(val){

	}

	ulong64( long val ) :data_((unsigned long)val){

	}

	ulong64( int val ) :data_((unsigned long)val){

	}

	ulong64( short val ) :data_((unsigned long)val){

	}

	ulong64( char val ) :data_((unsigned long)val){

	}

	ulong64( const ulong64& rhs ) :data_(rhs.data_){
		
	}

	ulong64& operator=( const ulong64& rhs ) {
		data_ = rhs.data_;

		return *this;
	}
	
	ulong64& operator=( const u64_t& rhs ) {
		data_ = rhs;
		return *this;
	}

	ulong64& operator=( const int64_t& rhs ) {
		data_ = rhs;
		return *this;
	}


	ulong64& operator=( const long& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const int& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const short& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const char& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const unsigned long& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const unsigned int& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const unsigned short& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const unsigned char& rhs ) {
		data_ = rhs;

		return *this;
	}

	ulong64& operator=( const double& rhs ) {
		data_ = (long)rhs;

		return *this;
	}

	ulong64& operator=( const float& rhs ) {
		data_ = (long)rhs;
		return *this;
	}



		
	ulong64& operator++() {
		data_ ++;
		return *this;
	}

	ulong64& operator--() {
		data_ --;
		return *this;
	}

	ulong64 operator+( const ulong64& rhs ) const {
		ulong64 result(*this);

		result.data_ += rhs.data_;

		return result;
	}


	ulong64 operator+( const unsigned long& rhs ) const{
		ulong64 result(*this);

		result.data_ += rhs;

		return result;
	}

	ulong64 operator+( const long& rhs ) const {
		ulong64 result(*this);

		result.data_ += rhs;

		return result;
	}

	ulong64 operator+( const int& rhs ) const{
		ulong64 result(*this);

		result.data_ += rhs;

		return result;
	}

	ulong64& operator+=( const unsigned long& rhs ) {
		
		data_ += rhs;

		return *this;
	}

	ulong64& operator+=( const ulong64& rhs ) {
		
		data_ += rhs.data_;

		return *this;
	}

	ulong64 operator*( const ulong64& rhs ) const {
		ulong64 result(*this);

		result.data_ *= rhs.data_;

		return result;
	}

	ulong64 operator*( const unsigned long& rhs ) const{
		ulong64 result(*this);

		result.data_ *= rhs;

		return result;
	}

	ulong64 operator*( const long& rhs ) const{
		ulong64 result(*this);

		result.data_ *= rhs;

		return result;
	}

	ulong64 operator*( const int& rhs ) const{
		ulong64 result(*this);

		result.data_ *= rhs;

		return result;
	}

	ulong64 operator/( const ulong64& rhs ) const{
		ulong64 result(*this);

		result.data_ /= rhs.data_;

		return result;
	}

	ulong64 operator/( const unsigned long& rhs ) const{
		ulong64 result(*this);

		result.data_ /= rhs;

		return result;
	}

	ulong64 operator/( const long& rhs ) const {
		ulong64 result(*this);

		result.data_ /= rhs;

		return result;
	}
	

	ulong64 operator/( int rhs ) const {
		ulong64 result(*this);

		result.data_ /= rhs;

		return result;
	}

	ulong64 operator/( const char& rhs ) const{
		ulong64 result(*this);

		result.data_ /= rhs;

		return result;
	}
	

	ulong64 operator%( const ulong64& rhs ) const{
		ulong64 result(*this);

		result.data_ %= rhs.data_;

		return result;
	}

	ulong64 operator%( const unsigned long& rhs ) const{
		ulong64 result(*this);

		result.data_ %= rhs;

		return result;
	}

	ulong64 operator%( const long& rhs ) const {
		ulong64 result(*this);

		result.data_ %= rhs;

		return result;
	}
	

	ulong64 operator%( int rhs ) const {
		ulong64 result(*this);

		result.data_ %= rhs;

		return result;
	}

	ulong64 operator%( const char& rhs ) const{
		ulong64 result(*this);

		result.data_ %= rhs;

		return result;
	}

	ulong64 operator-( const ulong64& rhs ) const{
		ulong64 result(*this);

		result.data_ -= rhs.data_;

		return result;
	}

	ulong64 operator-( const unsigned long& rhs ) const{
		ulong64 result(*this);

		result.data_ -= rhs;

		return result;
	}

	ulong64 operator-( const long& rhs ) const{
		ulong64 result(*this);

		result.data_ -= rhs;

		return result;
	}

	ulong64& operator-=( const ulong64& rhs ) {
		
		data_ -= rhs.data_;

		return *this;
	}

	ulong64& operator-=( const unsigned long& rhs ) {
		
		data_ -= rhs;

		return *this;
	}

	//comparison

	bool operator> (const ulong64& rhs ) const{
		return data_ > rhs.data_;
	}

	bool operator< (const ulong64& rhs ) const{
		return data_ < rhs.data_;
	}

	bool operator>= (const ulong64& rhs ) const{
		return data_ >= rhs.data_;
	}

	bool operator<= (const ulong64& rhs ) const{
		return data_ <= rhs.data_;
	}

	bool operator!= (const ulong64& rhs ) const{
		return data_ != rhs.data_;
	}

	bool operator== (const ulong64& rhs ) const{
		return data_ == rhs.data_;
	}
	
	//converstion routines
	
	operator char() const {
		return (char)data_;
	}

	operator unsigned char() const {
		return (unsigned char)data_;
	}

	operator short() const {
		return (short)data_;
	}

	operator unsigned short() const {
		return (unsigned short)data_;
	}

	operator long() const {
		return (long)data_;
	}

	operator unsigned long() const {
		return (unsigned long)data_;
	}

	operator int() const {
		return (int)data_;
	}

	operator unsigned int() const {
		return (unsigned int)data_;
	}

	operator double() const {
		return (double)(int64_t)data_;//(signed __int64)data_;
	}

	/**
	This returns the top 32 bits of the number
	*/
	unsigned long hi() const {
		unsigned long result = 0;
		result = data_ >> 32;
		return result;
	}

	/**
	This returns the low 32 bits of the number
	*/
	unsigned long lo() const {
		unsigned long result = 0;
		result = data_ & 0xffffffff;
		return result;
	}

	void hi( unsigned long val ) {		
		u64_t tmp = val;
		tmp = tmp << 32;
		data_ = tmp | (data_ & 0xffffffff);
	}

	void lo( unsigned long val ) {
		/**
		kind of hacky but GCC won't let me do this
		data_ = val | (data_ & 0xffffffff00000000);
		since it complains about a constant value being too big. 
		Cie la vie! :)
		*/

		u64_t tmp = data_ >> 32;
		data_ = (tmp << 32) | val;
	}

	u64_t data_;	
};


};// end of namespace 

#endif // _VCF_VCFULONG64_H__


