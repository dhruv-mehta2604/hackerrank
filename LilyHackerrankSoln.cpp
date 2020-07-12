#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

 int lilysHomework(vector<int> v) 
{
    map<int,int> mp1,mp2;int n1=0,n2=0;
    int n=v.size();int index;
    for(int i=0;i<n;i++){
        mp1[v[i]]=i;
        mp2[v[i]]=i;
    }
    vector<int> v1,v2,v3;
    v1=v;v2=v;v3=v;
    sort(v1.begin(),v1.end());
    sort(v3.begin(),v3.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(v1[i]!=v2[i]){
            index=mp1[v1[i]];
            mp1[v2[i]]=index;mp1[v1[i]]=i;
            swap(v2[index],v2[i]);
            n1++;
        }
        if(v3[i]!=v[i]){
            index=mp2[v3[i]];
            mp2[v[i]]=index;mp2[v3[i]]=i;
            swap(v[index],v[i]);
            n2++;
        }
    }
    return n1<n2?n1:n2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
