# Linkar C Framework

Linkar Framework is a set of open-source libraries that allows developers to create their own applications that connect to the linked Linkar Server to access the different MV Data-bases.

Linkar Framework is made up of a total of 15 libraries. 14 of them are open source. Only one is private and delivered compiled. This private library basically has two functions; one is to execute Persistent operations and the other to execute Direct operations:

- Persistent operations require a session to be established and closed through “Login” and “Logout” operations. The connection credentials to Linkar Server are supplied in the "Log-in" operation. Once the session is established, any operation can be executed without having to re-supply credentials.
- Direct operations do not require a session to be established. The connection credentials must always be supplied to the Linkar Server with each operation.

These two "primitive" functions, allow developers to create CRUD applications and call MV Basic subroutines across the Linkar Server. Developing an application with just these two primitives would be very difficult and time expensive.

The other 14 libraries are open-source. Developers can always design their own new custom libraries in two different ways:

- Relying on open source libraries, and designing a new one from them.
- Modifying the open-source libraries to adapt them to the specific needs of their application.

These libraries provide functions that allow the MV type input and output buffers to be conveniently manipulated. One of them also allows "Commands" to be executed (operations cre-ated using templates in XML or JSON format) across the Linkar Server. 

These libraries help developers to create applications faster. Some of them are based on the two primitive ones. For example, there are libraries that allow operations with input and output data in XML or JSON format. There are also libraries that allow you to work with input and output data in a very similar format to an MV buffer.

Developers will find functions to synchronously and asynchronously execute operations, in all these libraries. Functions that work in asynchronous mode instead of returning an object of the "string" type, return an object of  "Task <string>" type. Asynchronous functions run on a different thread than the main one, allowing the main thread not have to wait until the end of the operation. (**not in C Library**)

Developers who want to create an application do not need to use all these libraries. They can just use the ones required for their purpose. The following section shows the hierarchy of the Linkar FRAMEWORK libraries that will help them select the  libraries needed in each case.

## Linkar Framework hierarchy

- Linkar (Private)
- Linkar.Functions (open-source) Dependencies: Linkar
- Linkar.Strings (open-source) Dependencies: Linkar
- Linkar.Commands (open-source) Dependencies: Linkar
- Linkar.Functions.Direct (open-source) Dependencies: Linkar, Linkar.Functions
	- Linkar.Functions.Direct.JSON (open-source)
	- Linkar.Functions.Direct.MV (open-source)
	- Linkar.Functions.Direct.TABLE (open-source)
	- Linkar.Functions.Direct.XML (open-source)
- Linkar.Functions.Persistent (open-source) Dependencies: Linkar, Linkar.Functions
	- Linkar.Functions.Persistent.JSON (open-source)
	- Linkar.Functions.Persistent.MV (open-source)
	- Linkar.Functions.Persistent.TABLE (open-source)
	- Linkar.Functions.Persistent.XML (open-source)
  
## Building Libraries

This framework can be compiled to obtain the x64/x86 Static/Dynamic C libraries of Linkar Framework

There is always a private library: Linkar.dll / Linkar.lib / Linkar.so / Linkar.a

In this repository you can find the source code to generate the pubic libraries.

There are scripts for Windows and Linux to help in the generation of the libraries.


## Building Linux Libraries

Use the script "build_x64_x86.sh" to build the linux x64 and x86 libraries.

The compiles libraries will be placed in "bin" folder. 

This script was tested in Ubuntu 20.4


## Building Windows Libraries

Use the script "build_x64_x86.cmd" to build the Windows x64 and x86 libraries.

You must execute the script from "x64 Native Tools Command Prompt for VS 2019" to build x64 Libraries
and from "x86 Native Tools Command Prompt for VS 2019" to build x86 libraries

The compiles libraries will be placed in "bin" folder. 


### Windows x64/x86 DINAMIC LIBRARIES

Linkar.dll (Private library)

Linkar.Strings.Helper.dll

Linkar.Strings.dll


Linkar.Functions.dll

Linkar.Functions.Direct.dll

Linkar.Functions.Direct.JSON.dll

Linkar.Functions.Direct.MV.dll

Linkar.Functions.Direct.TABLE.dll

Linkar.Functions.Direct.XML.dll

Linkar.Functions.Persistent.dll

Linkar.Functions.Persistent.JSON.dll

Linkar.Functions.Persistent.MV.dll

Linkar.Functions.Persistent.TABLE.dll

Linkar.Functions.Persistent.XML.dll

Linkar.Commands.Direct.JSON.dll

Linkar.Commands.Direct.XML.dll

Linkar.Commands.Persistent.JSON.dll

Linkar.Commands.Persistent.XML.dll


### Windows x64/x86 STATIC LIBRARIES

Linkar.lib (Private library)

Linkar.Strings.Helper.lib

Linkar.Strings.lib


Linkar.Functions.lib

Linkar.Functions.Direct.lib

Linkar.Functions.Direct.JSON.lib

Linkar.Functions.Direct.MV.lib

Linkar.Functions.Direct.TABLE.lib

Linkar.Functions.Direct.XML.lib

Linkar.Functions.Persistent.lib

Linkar.Functions.Persistent.JSON.lib

Linkar.Functions.Persistent.MV.lib

Linkar.Functions.Persistent.TABLE.lib

Linkar.Functions.Persistent.XML.lib

Linkar.Commands.Direct.JSON.lib

Linkar.Commands.Direct.XML.lib

Linkar.Commands.Persistent.JSON.lib

Linkar.Commands.Persistent.XML.lib


### Linux x64/x86 DYNAMIC LIBARIES (*.so)

libLinkar.so (Private library)


libLinkar.Strings.Helper.so

libLinkar.Strings.so


libLinkar.Functions.so

libLinkar.Functions.Direct.JSON.so

libLinkar.Functions.Direct.MV.so

libLinkar.Functions.Direct.so

libLinkar.Functions.Direct.TABLE.so

libLinkar.Functions.Direct.XML.so

libLinkar.Functions.Persistent.JSON.so

libLinkar.Functions.Persistent.MV.so

libLinkar.Functions.Persistent.so

libLinkar.Functions.Persistent.TABLE.so

libLinkar.Functions.Persistent.XML.so

libLinkar.Commands.Direct.JSON.so

libLinkar.Commands.Direct.XML.so

libLinkar.Commands.Persistent.JSON.so

libLinkar.Commands.Persistent.XML.so


### Linux x64/x86 STATIC LIBARIES (*.a)

libLinkar.a (Private library)


libLinkar.Functions.a

libLinkar.Functions.Direct.JSON.a

libLinkar.Functions.Direct.MV.a

libLinkar.Functions.Direct.TABLE.a

libLinkar.Functions.Direct.XML.a

libLinkar.Functions.Persistent.JSON.a

libLinkar.Functions.Persistent.MV.a

libLinkar.Functions.Persistent.TABLE.a

libLinkar.Functions.Persistent.XML.a

libLinkar.Commands.Direct.JSON.a

libLinkar.Commands.Direct.XML.a

libLinkar.Commands.Persistent.JSON.a

libLinkar.Commands.Persistent.XML.a
