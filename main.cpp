#include <iostream>
#include <cmath>
using namespace std;

void Palindrom(int Tab[1000], int Roz[100], int, int);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k, l=0;
	cin>>k;
	
	int T[k];
	int R[100];
	
	for(int i=0; i<k; ++i){
		cin>>T[i];
	}
	
	Palindrom(T, R, k, l);
}

void Palindrom(int Tab[1000], int Roz[100], int n, int i)
{
		while(i!=n){
		int licznik=0;
		jump:
		int liczba = Tab[i], j=0;
		
		while(liczba!=0){
			Roz[j] = liczba%10;
			liczba = (liczba-Roz[j])/10;
			j++;
		}
		
		int kon=j-1;
		bool palindrom = true;
		
		for(int k=0; k<j; ++k){
			if(Roz[k] != Roz[kon]){
				palindrom = false;
				break;
			}
			kon--;
		}
		
		if(palindrom)	cout<<Tab[i]<<" "<<licznik<<'\n';
		else{
			licznik++;
			int koncowa=0, iterator=0;
			
			for(int l=j-1; l>=0; l--){
				koncowa += Roz[iterator]*pow(10,l);
				iterator++;
			}
			Tab[i]+=koncowa;
			goto jump;					//ZMIENIC
		}		
		j=0;
		i++;
	}	
}
