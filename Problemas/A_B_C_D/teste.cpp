#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n,d=0,k,di;

int main(){
	while (scanf("%d",&n) != EOF) {
		d = 0;
		priority_queue<int> pq;
				for (int i=0; i<n; i++) {
							string s = "";
										cin >> s;
													if (s == "C") {
																	cin >> s;
																					if (s == "Denis") {
																										d=1;
																															cin >> di; 				
																																			}
																																							else {
																																												cin >> k;
																																																	pq.push(k);
																																																					}
																																																								}
																																																											else if (s == "A" && pq.size() != 0) {
																																																															if (d) {
																																																																				cout << di << "\n";
																																																																									d=0;				
																																																																													}
																																																																																	else {
																																																																																						cout << pq.top() <<"\n";
																																																																																											pq.pop();
																																																																																															}
																																																																																																		}
																																																																																																				}
																																																																																																					}		

																																																																																																					}
