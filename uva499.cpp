#include <cstdio>
#include <map>
//#include <utility>
#include <vector>
#include <algorithm>

//map与pair的应用，map按value排序，operator重载
// Created by beans on 2016/12/8.
//
typedef std::pair<char , int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
}
std::map<char,int> m;
int res[123];
char tmp[10000];
struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        if(lhs.second==rhs.second)
            return lhs.first<rhs.first;
        else
            return lhs.second > rhs.second;
    }
};
void main(){
    while(gets(tmp)){
        m.clear();
        for (int i = 0; i < 10000; ++i) {
            if(tmp[i]=='\0')
                break;
            if(tmp[i]>122||(tmp[i]<97&&tmp[i]>90)||tmp[i]<65)
                continue;
            if(m.find(tmp[i])!=m.end())
                m[tmp[i]] += 1;
            else
                m.insert(std::map<char ,int> :: value_type(tmp[i],1));
        }
        std::vector<PAIR> sort_map_by_value(m.begin(), m.end());
        std::sort(sort_map_by_value.begin(), sort_map_by_value.end(), CmpByValue());
        // sort(sort_map_by_value.begin(), sort_map_by_value.end(), cmp_by_value);
        int first = sort_map_by_value[0].second;
        for (int i = 0; i != sort_map_by_value.size(); ++i) {
            if(sort_map_by_value[i].second==first)
                printf("%c",sort_map_by_value[i].first);
        }
        printf(" %d\n",first);

    }
}
