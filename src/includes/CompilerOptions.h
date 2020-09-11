/*
	File: CompilerOptions.h
	Header file for constants definition to be used by Windows and Linux compilers.
	
	--- Code
	#ifdef __LK_DYNAMIC_LIB__
		#ifdef _MSC_VER
			#ifdef __LK_EXPORT__
				#define DllEntry __declspec(dllexport)
			#else
				#define DllEntry __declspec(dllimport)
			#endif	
		#else
			#ifdef __GNUC__
			// Gnu C
				#if __GNUC__ >= 4
					#define DllEntry __attribute__ ((visibility ("default")))
				#else
					#define DllEntry
				#endif
			#else
				#define DllEntry
			#endif
		#endif
	#else
		#ifdef __LK_STATIC_LIB__
			#ifdef _MSC_VER
				#define DllEntry
			#else
				#ifdef __GNUC__
				// Gnu C
					#if __GNUC__ >= 4
						#define DllEntry __attribute__ ((visibility ("default")))
					#else
						#define DllEntry
					#endif
				#else
					#define DllEntry
				#endif		
			#endif
		#else
			#define DllEntry
		#endif
	#endif
		---
*/
#ifdef __LK_DYNAMIC_LIB__
	#ifdef _MSC_VER
		#ifdef __LK_EXPORT__
			#define DllEntry __declspec(dllexport)
		#else
			#define DllEntry __declspec(dllimport)
		#endif	
	#else
		#ifdef __GNUC__
		// Gnu C
			#if __GNUC__ >= 4
				#define DllEntry __attribute__ ((visibility ("default")))
			#else
				#define DllEntry
			#endif
		#else
			#define DllEntry
		#endif
	#endif
#else
	#ifdef __LK_STATIC_LIB__
		#ifdef _MSC_VER
			#define DllEntry
		#else
			#ifdef __GNUC__
			// Gnu C
				#if __GNUC__ >= 4
					#define DllEntry __attribute__ ((visibility ("default")))
				#else
					#define DllEntry
				#endif
			#else
				#define DllEntry
			#endif		
		#endif
	#else
		#define DllEntry
	#endif
#endif
