#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define pb push_back
#define MID (low+high)/2  // f(x) degrau 01 (_--)
#define MID2 (low+high+1)/2 // f(x) degrau 10 (--_)

using namespace std;

int c[10000]; //qtde q demanda o voo
int r[10000]; //qtde q pode reabast

vector<int> gain; // ganho do voo, no caso contera apenas valores negativos

/// Ã© 
bool func_oracle (int nVoos, int fuel){ 
	int counter=0;
	while(counter < nVoos && fuel >= 0 ){
		fuel = fuel + gain[counter++];
	}
	if (fuel>=0 && counter == nVoos){
		// cout <<"Deu pra voar "<<counter<<endl;
		return true;
	}
	return false;
}

bool comp(int a, int b){
	return a>b;
}


int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	int value=0, n=0, m=0, f=0;
	string str;

	int mid, low, high, number_flights;

	
	while(cin >> n >> f) {
		gain.clear();
		for(int i=0; i<n; i++){ 
			cin >> value;
			c[i] = value;
		}
		
		for(int j=0; j<n; j++){
			cin >> value;
			// r[j] = value;
			gain.push_back(value - c[j]);
			// cout << "gain("<<j<<"): "<< gain[j]<<"\n";
		}

		sort(gain.begin(), gain.end(), comp);
		// for(int k=0; k<n; k++){
		// 	cout << gain[k] << " ";
		// }
		// cout << endl;
		////bin search:
		low=0;
		high=n;
		while (low <= high) {
			cout << low << " " << high << endl;
			mid = MID;
			// cout << "low = "<<low<<" high = "<<high<< "mid = "<<mid<<endl;
			if(func_oracle(mid, f)){ // Can I do mid fligths with f
				low = mid+1;
				number_flights = mid;
			}else{
				high = mid-1;
			}
		}
		if (func_oracle(mid, f))	mid--;
		// cout << "number_flights = " << number_flights << "\n";
		cout << mid << "\n";


	}	
	return 0;
}