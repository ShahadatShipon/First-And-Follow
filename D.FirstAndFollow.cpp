#include<bits/stdc++.h>
using namespace std;
int main() {
    vector <string> vectors;

    vectors.push_back("E=Te");
    vectors.push_back("e=+Te");
    vectors.push_back("e=#");
    vectors.push_back("T=Ft");
    vectors.push_back("t=*Ft");
    vectors.push_back("t=#");
    vectors.push_back("F=(E)");
    vectors.push_back("F=i");

    cout<<"Grammar ->"<<endl;

    for(int i=0; i!=vectors.size(); i++) {
        cout<<"\t"<<vectors[i]<<"\n";
    }
    cout<<"\n\n";

    int i=0;
start_first:
    while(i!=vectors.size()) {
        if((i>0)&&(vectors[i].at(0)==vectors[i-1].at(0))) {
            i++;
            continue;
        } else {
            cout<<"First("<<vectors[i].at(0)<<") = {";
            for(int j=0; j!=vectors.size(); j++) {
                if(vectors[i].at(2)==vectors[j].at(0)) {
                    for(int k=0; k!=vectors.size(); k++) {
                        if(vectors[j].at(2)==vectors[k].at(0)) {
                            cout<<vectors[k].at(2)<<",";
                            if(vectors[k].at(0)==vectors[k+1].at(0)) {
                                cout<<vectors[k+1].at(2);
                            }
                            cout<<"}\n";
                            i++;
                            goto start_first;
                        }
                    }
                    cout<<vectors[j].at(2)<<",";
                    if(vectors[j].at(0)==vectors[j+1].at(0)) {
                        cout<<vectors[j+1].at(2);
                    }
                    cout<<"}\n";
                    i++;
                    goto start_first;
                }
            }
            cout<<vectors[i].at(2)<<",";
            if(vectors[i].at(0)==vectors[i+1].at(0)) {
                cout<<vectors[i+1].at(2);
            }
            cout<<"}\n";
            i++;
            goto start_first;
        }
    }
    cout<<endl<<endl;

    string save,rr,last=",$}";
    vector<string> v_s;
    int a=0,e=0;
start_follow:
    while(a!=vectors.size()) {
        if((a>0)&&(vectors[a].at(0)==vectors[a-1].at(0))) {
            a++;
            continue;
        } else {
            rr = vectors[a].at(0);
            save.append(rr);
            save.append("=");
            cout<<"Follow("<<vectors[a].at(0)<<") = {";
            for(int b=0; b!=vectors.size(); b++) {
                for(int c=2; c!=vectors[b].size(); c++) {
                    if(vectors[a].at(0)==vectors[b].at(c)) {
                        if(vectors[b].at(c)==vectors[b].at(vectors[b].size()-1)) {
                            for(int e=0; e!=vectors.size(); e++) {
                                if(vectors[b].at(0)==v_s[e].at(0)) {
                                    for(int f=2; f!=v_s[e].size(); f++) {
                                        cout<<v_s[e].at(f);
                                        rr = v_s[e].at(f);
                                        save.append(rr);
                                    }
                                    cout<<endl;
                                    a++;
                                    v_s.push_back(save);
                                    save = "";
                                    goto start_follow;
                                }
                            }
                        } else {
                            for(int d=0; d!=vectors.size(); d++) {
                                if(vectors[b].at(c+1)==vectors[d].at(0)) {
                                    cout<<vectors[d].at(2)<<",";
                                    rr = vectors[d].at(2);
                                    save.append(rr);
                                    rr = ",";
                                    save.append(rr);
                                    if(vectors[d].at(0)==vectors[d+1].at(0)) {
                                        if(vectors[d+1].at(2)=='#') {
                                            for(int f=2; f!=v_s[b].size(); f++) {
                                                cout<<v_s[b].at(f);
                                                rr = v_s[b].at(f);
                                                save.append(rr);
                                            }
                                            cout<<endl;
                                            a++;
                                            v_s.push_back(save);
                                            save = "";
                                            goto start_follow;
                                        } else {
                                            cout<<vectors[d+1].at(2);
                                            rr = vectors[d+1].at(2);
                                            save.append(rr);
                                        }
                                    }
                                    cout<<endl;
                                    a++;
                                    v_s.push_back(save);
                                    save = "";
                                    goto start_follow;

                                }
                            }
                            rr = vectors[b].at(c+1);
                            save.append(rr);
                            cout<<vectors[b].at(c+1)<<",$}"<<endl;
                            save.append(last);
                            v_s.push_back(save);
                            save = "";

                            a++;
                            goto start_follow;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

