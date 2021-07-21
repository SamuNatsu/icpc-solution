#include <cstdio>
#include <cstring>

#include <string>
#include <unordered_map>

#define ll long long

const int next[6] = {-1, 0, -1, 0, 2};
const char m[] = "haha";
ll count(const char* str) {
    ll rtn = 0;
    for (int i = 0, j = 0; str[i]; )
        if (j == -1 || str[i] == m[j]) {
            ++i;
            ++j;
            if (j == 4) {
                ++rtn;
                j = next[j];
            }
        }
        else 
            j = next[j];
    return rtn;
}

int t, n;
char tmp1[10], tmp2[10], tmp3[10];

struct nd {
    std::string pre, post;
    ll cnt;
};

std::string lst;
std::unordered_map<std::string, nd> mp;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        while (n--) {
            scanf("%s%s", tmp1, tmp2);
            lst = tmp1;
            if (tmp2[0] == ':') {
                scanf("%s", tmp2);
                int len = strlen(tmp2);
                if (len <= 3) {
                    mp[tmp1].pre = tmp2;
                    mp[tmp1].post = tmp2;
                    mp[tmp1].cnt = 0;
                }
                else {
                    mp[tmp1].pre = std::string(tmp2).substr(0, 3);
                    mp[tmp1].post = std::string(tmp2).substr(len - 3, 3);
                    mp[tmp1].cnt = count(tmp2);
                }
            }
            else {
                scanf("%s + %s", tmp2, tmp3);
                mp[tmp1].cnt = mp[tmp2].cnt + mp[tmp3].cnt + count((mp[tmp2].post + mp[tmp3].pre).c_str());
                if (mp[tmp2].pre.length() <= 3) {
                    std::string ss = mp[tmp2].pre + mp[tmp3].pre;
                    mp[tmp1].pre = ss.length() <= 3 ? ss : ss.substr(0, 3);
                }
                else
                    mp[tmp1].pre = mp[tmp2].pre;
                if (mp[tmp3].post.length() <= 3) {
                    std::string ss = mp[tmp2].post + mp[tmp3].post;
                    mp[tmp1].post = ss.length() <= 3 ? ss : ss.substr(ss.length() - 3, 3);
                }
                else 
                    mp[tmp1].post = mp[tmp3].post;
            }
        }
        printf("%lld\n", mp[lst].cnt);
    }
    return 0;
}
