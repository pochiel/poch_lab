#include <stdio.h>
void main(){
	static char c;
	static char a;
	c++;a++;c=c<<c<<c<<c<<c<<c;a=a<<a<<a<<a;c+=a;
	printf("%s",c);
	c=c<<c<<c<<c<<c<<c;a=a<<a<<a<<a;c+=a;
	printf("%s",c);
}
