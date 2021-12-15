#include<iostream>
using namespace std;
class Time {
	public:
		void set_time() {
			cin >> hour;
			cin >> minute;
			cin >> sec;
		}
		void show_time() {
			cout << hour << ":" << minute << ":" << sec << endl;
		}
	private:
		int hour;
		int minute;
		int sec;
};

int main() {
	Time t;
	t.set_time();
	t.show_time();
	return 0;
}

//void Time::set_time(void){
//	cin>>t.hour;
//	cin>>t.minute;
//	cin>>t.sec;
//}
//void Time::show_time(void){
//	cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
//}
