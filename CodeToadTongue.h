#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <msclr\marshal.h>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <locale>
#include <sstream>

using namespace System;
using namespace System::Runtime::InteropServices;

//* STRIGN MANIPULATION */
//TRIMMING
// trim from end
static inline string &rtrim(string &s) {
		s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
		return s;
}
//// trim from start
static inline string &ltrim(string &s) {
		s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
		return s;
}
//// trim from both ends
static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
}

double string_to_double( const std::string& s ) {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
	 return 0;
   return x;
 }
string Line(int a){
	string l = "*";
	for(int i = 0; i < a-2; i++) l+="-";
	return l+"*";
}