#include<iostream>
using namespace std;
class Time {
	public:
		void set_time(void);
		void show_time(void);
		int hour;
		int minute;
		int sec;
};
Time t;
void set_time(void);
void show_time(void);
int main() {

	set_time();
	show_time();
	return 0;
}


void set_time(void) {
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}
void show_time(void) {
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
