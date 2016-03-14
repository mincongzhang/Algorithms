#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

int * buildNext( char * pattern ){
	size_t pattern_len = strlen(pattern), pattern_i = 0; 
	int * N = new int[pattern_len];        //next[]
	int t = N[0] = -1;           //pattern[-1] wildcard

	while (pattern_i < pattern_len - 1 ){
		if( t < 0 || pattern[pattern_i] == pattern[t] ){ //match
			pattern_i++; t++;
			N[ pattern_i ] = (pattern[pattern_i] != pattern[t] ? t : N[t] );
		} else { //mismatch
			t = N[t];
		}
	}

	return N;
}

int match(char * text, char * pattern){
	int * next = buildNext(pattern);
	int text_len = (int)strlen(text), text_i = 0; 
	int pattern_len = (int)strlen(pattern), pattern_i = 0;

	std::cout<<"text:"<<text<<std::endl;
	std::cout<<"text len:"<<text_len<<std::endl;
	std::cout<<"pattern:"<<pattern<<std::endl;
	std::cout<<"pattern len:"<<pattern_len<<std::endl;

	while( pattern_i < pattern_len && text_i < text_len ){
		if( pattern_i < 0 || text[text_i] == pattern[pattern_i] ){ //pattern_i<0 means get next[0] == -1
			text_i++; pattern_i++;
		} else {	//pattern move right, text no backout
			pattern_i = next[pattern_i];
		}
	}

	delete [] next;

	return text_i - pattern_i;
}

int main(){
	std::cout<<"KMP:"<<std::endl;

	int m = match("abchichisnllabbba","chichinlla");

	std::cout<<m<<std::endl;

	system("PAUSE");
}
