/*

	(c) 2022 Arthur 'ArTDsL' Dias dos Santos Lasso.
	https://www.artdsl.space/

	* PROJECT MADE PUBLIC UNDER MIT LICENSE *

	- https://github.com/ArTDsL/ARTDSL-ICL-SAMP/


	##
		Name: ART_DEFINITIONS.inc
		Creation date: 2022/04/30
		Last Update: 2022/05/03
	##

*/
new __ARTDSL_inlinemsg[256];
#if !defined PFWD
	#define PFWD::%0(%1)	forward %0(%1);\
							public %0(%1)
#endif
#if !defined INFINITY_LIFE
	#define INFINITY_LIFE (Float:0x7F800000)
#endif
#if !defined is_null
	#define is_null(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
#if !defined PRESSED
	#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif
#if !defined inline_format
	#define inline_format(%0,%1) (format(__ARTDSL_inlinemsg,sizeof(__ARTDSL_inlinemsg),%0,%1), __ARTDSL_ret_inlineMsg())
#endif