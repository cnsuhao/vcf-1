//Reflection.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;






/**
This short example will demonstrate how to create a 
specific instance of class given the class's class name
or UUID identifier. 
*/

/**
first define a string that will represen the class's UUID or unique
identifier. Technically it can be anything you want (you could 
use "abcde" but that's not very unique!), but the norm is to use
a UUID generated by some tool. The name of the #define is typically
the class name, followed by an "_", followed by "CLASSID"
*/
#define SIMPLECLASS_CLASSID		"FB685669-6D44-4ea7-8011-B513E3808002"

/**
Define your class.
Make sure the class derives from VCF::Object, either directly or 
indirectly.
*/
class SimpleClass : public VCF::Object {
public:
	/**
	Define you're class's Reflection (or RTTI if you prefer) information:
	use the BEGIN_CLASSINFO() and END_CLASSINFO() macros for this.
	BEGIN_CLASSINFO takes as it's arguments the class, the class name (as a 
	string), the super class name (as a string) which must be itself either
	VCF::Object or some class that ultimately derives from VCF::Object, 
	and the class's UUID string. Please note that if you class is within a 
	namespace to use the namespace qualifier as the class name. Thus if 
	we had class Foo, that was part of the Bar namespace, we would refer
	to the Foo class's name as "Bar::Foo" not "Foo". The same also applies
	to the super class name.
	You end your class's reflection info calling the END_CLASSINFO macro, and 
	pass in the class as its sole argument.
	*/
	BEGIN_CLASSINFO( SimpleClass, "SimpleClass", "VCF::Object", SIMPLECLASS_CLASSID )
	END_CLASSINFO( SimpleClass )
		

	/**
	You must define at least a default constructor that either take no arguments
	or if it must take arguments, then sensible defaults such that the class
	can be created and rely on the default arguments for a valid instance.
	*/
	SimpleClass(){};


	virtual ~SimpleClass(){ 
		
	}
};


void createFromName()
{	
	/**	
	Once you have defined your class you must register it.
	Typically this is done in your start up code, after 
	the FoundationKit itself has been intialized. Please
	see the main() of this example to see this being done.
	To register the class you can simply call the REGISTER_CLASSINFO()
	macro and pass in the class.

	To create an instance of your class you msut first access the class
	registry via the ClassRegistry::getClassRegistry(), then
	call the createNewInstance() method of the ClassRegistry, passing 
	in the name of your class. Note the try/catch section, if the ClassRegistry
	is unable to create an instance of the class requested it will 
	throw a CantCreateObjectException.
	*/	

	try {
		Object* newInstance = ClassRegistry::createNewInstance( "SimpleClass" );
		
		System::print( "Created newInstance class name: %s\n", newInstance->getClassName().c_str() );

		// we're done, free the object
		newInstance->free();
	}
	catch (CantCreateObjectException& ){
		System::print( "Unable to create class instance\n" );
	}
	catch (...){
		throw BasicException( "Unknown exception" );
	}

	System::print( "\n" );
}

void createFromUUID()
{	
	/**	
	Similar to creating a class by name, only this time we will use the 
	class's UUID to refer to it. This can be considered a more "precise" way
	to create the class as it prevents the accidental naming collision, 
	particularly if you have used a true UUID value for your class's id.

	*/	

	try {
		Object* newInstance = 
			ClassRegistry::createNewInstanceFromClassID( SIMPLECLASS_CLASSID );
		
		System::print( "Created newInstance class name: %s\n", newInstance->getClassName().c_str() );
		// we're done, free the object
		newInstance->free();
	}
	catch (CantCreateObjectException& ){
		System::print( "Unable to create class instance\n" );
	}
	catch (...){
		throw BasicException( "Unknown exception" );
	}

	System::print( "\n" );
}




/**
You can create an interface and associate the interface with a class
*/


/**
first define a string that will represen the interfaces's UUID or unique
identifier. 
*/
#define HELLOWORLDINTERFACE_ID		"b89a0f94-583a-4563-8a63-e159072584b2"

/**
define a an interface. An interface (in C++) must have all it's 
methods virtual pure, to mark the class as an abstract class that
cannot be created directly. 
The reflection information is declared much like our SimpleClass before,
only now we use BEGIN_INTERFACEINFO/END_INTERFACEINFO instead of 
BEGIN_CLASSINFO/END_CLASSINFO macros to mark the beginning and end of 
the reflection information.


*/
class HelloWorldInterface {
public:

	BEGIN_INTERFACEINFO(HelloWorldInterface,"HelloWorldInterface","Interface",HELLOWORLDINTERFACE_ID)
	INTERFACE_METHOD_VOID( HelloWorldInterface, helloWorld);
	END_INTERFACEINFO(HelloWorldInterface)


	virtual ~HelloWorldInterface(){};

	/**
	virtual pure method declaration for each interface method
	*/
	virtual void helloWorld() = 0;
};



/**
define the class's class ID.
*/
#define HELLOWORLD_CLASSID		"16db9219-e4b4-4ed8-937a-657b83dd94ed"

/**
define a class that implements the interface.
Notice the addition of the IMPLEMENTS_INTERFACE macro. This 
will tell the ClassRegistry that our HelloWorld class does
indeed implement the HelloWorldInterface.
*/

class HelloWorld : public VCF::Object, public HelloWorldInterface {
public:
	BEGIN_CLASSINFO( HelloWorld, "HelloWorld", "VCF::Object", HELLOWORLD_CLASSID )
	IMPLEMENTS_INTERFACE(HelloWorld,HelloWorldInterface,"HelloWorld","HelloWorldInterface",HELLOWORLDINTERFACE_ID,"Interface")
	END_CLASSINFO(HelloWorld)

	HelloWorld() {}

	virtual ~HelloWorld() {
		System::print( "HelloWorld instance destroyed\n" );
	}

	virtual void helloWorld() {
		System::print( "Hello World!\n" );
	}

};


void createAnInterface()
{
	
	try {

		/**
		Since HelloWorld is the actual class that implements the 
		HelloWorldInterface
		*/

		HelloWorldInterface* helloWorld = 
			(HelloWorldInterface*) ClassRegistry::createNewInterfaceInstanceFromInterfaceName( "HelloWorldInterface", "HelloWorld" );
		
		helloWorld->helloWorld();
		
		delete helloWorld;
	}
	catch (CantCreateObjectException& ){
		System::print( "Unable to create class instance\n" );
	}

	System::print( "\n" );
}


#define CLASSWITHMETHODS_CLASSID		"3a5537b3-6435-4412-8d91-84b1ceab398d"

/**
Lets extend the SimpleClass class and add some methods to it.
*/
class ClassWithMethods : public SimpleClass {
public:
	BEGIN_CLASSINFO( ClassWithMethods, "ClassWithMethods", "SimpleClass", CLASSWITHMETHODS_CLASSID )
	METHOD_VOID( ClassWithMethods, doit )
	METHOD_2VOID( ClassWithMethods, twoDoubles, const double&, double, "dd" )
	END_CLASSINFO( ClassWithMethods )
		

	ClassWithMethods(){};


	virtual ~ClassWithMethods(){ 
		
	}

	void doit()
	{
		System::print( "doit called\n" );
	}

	void twoDoubles( const double& x, double y ) {
		System::print( "twoDoubles( %0.3f, %0.3f ) called\n", x, y );
	}
};


/**
this will demonstrate how to get Class information from a given object instance
*/
void outputClassInfo( Object* o )
{
	Class* clazz = o->getClass();

	System::print( clazz->getClassName() + "\n" );
	System::print( clazz->getID() + "\n" );
	

	System::print( "Method count: " + StringUtils::toString( clazz->getMethodCount() ) + "\n" );
	Enumerator<Method*>* methods = clazz->getMethods();
	while ( methods->hasMoreElements() ) {
		
		Method* method = methods->nextElement();
		
		System::print( "\tMethod name: \"%s\", number of arguments: %d\n",
			method->getName().c_str(), method->getArgCount() );
		
		if ( method->getArgCount() == 0 ) {
			//if the method has no args, lets invoke it

			System::print( "invoking method for Object: %s\n", o->toString().c_str() );
			method->invoke( NULL );

			System::print( "\n\n" );
		}		
	}

	System::print( "Property count: " + StringUtils::toString( clazz->getPropertyCount() ) + "\n" );

	System::print( "\n" );
}


/**
Here we'll create an instance of ClassWithMethods dynamically, and then
invoke the method "twoDoubles" if exists
*/
void createAndInvoke()
{
	try {
		Object* newInstance = ClassRegistry::createNewInstance( "ClassWithMethods" );
		
		System::print( "Created newInstance class name: %s\n", newInstance->getClassName().c_str() );

		Class* clazz = newInstance->getClass();
		Method* twoDoubles = clazz->getMethod( "twoDoubles" );

		if ( NULL != twoDoubles ) {
			VariantData* args[2] = {new VariantData(12.23),new VariantData(32.45)};

			twoDoubles->invoke( &args[0] );

			delete args[0];
			delete args[1];
		}

		// we're done, free the object
		newInstance->free();
	}
	catch (CantCreateObjectException& ){
		System::print( "Unable to create class instance\n" );
	}
	catch (...){
		throw BasicException( "Unknown exception" );
	}
}


int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	/**
	All classes are registered here, once
	*/
	REGISTER_CLASSINFO(SimpleClass);
	REGISTER_INTERFACEINFO( HelloWorldInterface );
	REGISTER_CLASSINFO(HelloWorld);
	REGISTER_CLASSINFO(ClassWithMethods);


	createFromName();

	createFromUUID();

	createAnInterface();
	

	SimpleClass simple;


	outputClassInfo( &simple );

	ClassWithMethods methods;

	outputClassInfo( &methods );

	createAndInvoke();


	FoundationKit::terminate();
	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.2.2.2  2004/04/29 03:04:28  marcelloptr
*reformatting of source files
*
*
*/


