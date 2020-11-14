#Sakostr
this a c11 standard library for working with strings in c language.<br><br>
<b>Methods : <b>
- getStrlen(char * str) : this function takes an string and returns the length of the string.<br>
example : <br>
_char ex[] = "github";<br>
int i = getStrLen(ex); // i = 6_
---
- getIndex(char * string, char c) : this function takes an string and a character and returns the first index of the character in the string or -1 if the string does not contain the character.<br>
example : <br>
_char ex[] = "github";<br>
char exc = 't';<br>
char exv = 'e';<br>
int index = getIndex(ex,exc); // index = 2<br>
int index2 = getIndex(ex,exv); // index2 = -1<br>_
---
- strComp(char * str1,char * str2) : compares to given strings and returns -1 if given strings are equal, otherwise returns the first character index they are different at.<br>
example : <br>
_char str1[] = "github";<br>
char str2[] = "github";<br>
char str3[] = "gitlab";<br>
int i = strComp(str1,str2); // i = -1<br>
int j = strComp(str1,str3); // j = 3<br>_
---
- strConcat(char * str1,char * str2) : appends two given string.<br>
example :<br>
_char str1[] = "git";<br>
char str2[] = "hub";<br>
printf("%s",strConcat(str1,str2)); // prints github.<br>_
---
- strContains(char * str,char * sub): checks if the given string contains the given substring, returns -1 if does not and the first index of the main string that substring appears at.<br>
example : <br>
_char ex[] = "github";<br>
char sub1[] = "hub";<br>
char sub2[] = "tub";<br>
int i = strContains(ex,sub1); // i = 3<br>
int j = strContains(ex,sub2); // j = -1<br>_
---
- subString(char * str, int start, int end) : this function returns a substring of the given string according to the start and end index.<br>
example : <br>
_char ex[] = "github";<br>
printf("%s",subString(ex,1,4)); // prints ith.<br>_
---
- strEndsWith(char * str, char * end) , strStartsWith(char * str, char * start) : these two methods check if the given string starts or ends with second string. they return 1 if true and 0 if false.<br>
example : <br>
_char ex[] = "github";<br>
char strt1[] = ="gi";<br>
char strt2[] = "fi";<br>
int i = strStartsWith(ex,strt1); // i = 1<br>
int j = strStartsWith(ex,strt2); // j = 0<br>_
---
- strToLower(char * str) , strToUpper(char * str) : these two functions (as you can tell by their name) turn all the characters in the given string to lowercase ot uppercase and return the new string.<br>
example : <br>
_char ex[] = "gItHuB";<br>
printf("%s",strToLower(ex)); // prints github.<br>
printf("%s",strToUpper(ex)); // prints GITHUB.<br>_
---
- strReplace(char * str,char * rep,char * new) : takes a substring (rep) and replaces it with another given string(new) in the main string(str). returns the new string or the original string if it does not contain the substring(rep).<br>
example : <br>
_char str[] = "github";<br>
char rep[] = "thu";<br>
char new[] = "olp";<br>
printf("%s",strReplace(str,rep,new)); // prints giolpb.<br>_
---
- parseString(long num) : takes an unsigned long number and return it as an string.<br>
example : <br>
_long num = 103678;<br>
printf("%s",parseString(num)); // prints "103678" (as an string).<br>_