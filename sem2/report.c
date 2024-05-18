#include<iostream>
using namespace std;

class Weather{

	public:
		int day_of_month;
		int hightemp;
		int lowtemp;
		int rain;
		int snow;
		
		Weather(){
			rain=0;
			snow=0;
			lowtemp=0;
			hightemp=0;
			day_of_month=0;
		}
		
		Weather(int r,int s,int low,int high,int day){
			rain=r;
			snow=s;
			lowtemp=low;
			hightemp=high;
			day_of_month=day;
		}
		
		void show(){
		    cout<< "Day " << day_of_month << endl;
			cout << "temp:" << lowtemp << "-" << hightemp <<" snow:"<<snow;
			cout << " rain:"<<rain <<"\n";
		}
};

int main(){
    Weather month[28];
	Weather w1;
	
	int r,s,low, high, day ;
	float avgRain=0,avgSnow=0,avgLow=0,avgHigh=0;
	int ch=0;
	bool b=true;
	while(b){
	    cout<< "\n";
	    cout << "1)enter 2)search day 3)Avg of month 4)exit";
	    cout << "\n give choice:";
	    cin >> ch;
	    
	    switch(ch){
	        
	       case 1:cout << "day:";
	                cin >> day;
	                cout << "rain:";
	                cin >> r;
	                cout << "snow:";
	                cin >> s;
	                cout << "low:";
	               cin >> low;
	               cout << "high:";
	               cin >> high;
	               
	               month[day].day_of_month=day;
	               month[day].rain=r;
	               month[day].snow=s;
	               month[day].lowtemp=low;
	               month[day].hightemp=high;
	                
	                month[day].show();
	                break;
	        case 2:cout << "enter day:";
	                cin >> day;
	                month[day].show();
	       case 3:
	                for(int i=0;i<28;i++){
	                    avgSnow+=month[i].snow;
	                    avgRain+=month[i].rain;
	                    avgLow+=month[i].lowtemp;
	                    avgHigh=month[i].hightemp;
	                }
	                
	                avgSnow/=28;
	                avgRain/=28;
	                avgHigh/=28;
	                avgLow/=28;
	       
	                cout << "Average:\n";
	                cout << "avg snow:"<< avgSnow <<"\navg rain:"<< avgRain ;
	                cout << "\navg low temp:" << avgLow << "\navg high temp:" << avgHigh;
	                break;
	        case 4:b=false;
	                break;
	        default:cout << "wrong";
	    }
	    
	}
}
