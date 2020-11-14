double pw(int base,int power){
    double out = base;
    if (power > 0){
        for (int i = 1 ; i < power ; i++){
            out *= base;
        }
    }else{
        out = 1;
    }
    return out;
}

char * parseString(long num){
    double in = (double)num;
    int y = 0;
    int dt = 0;
    static char out[2048] = {};
    char nums[] = "0123456789";
    if (num/1 != 0) {
        for (int i = 0; i < 20; i++) {
            double hds = pw(10,-(i-19));
            int j = (int)(in / (double) hds);
            if (dt == 0) {
                if (j != 0) {
                    dt = 1;
                    if(num > 0){
                        out[y] = nums[j];
                    }else{
                        out[0] = '-';
                        out[y+1] = nums[-j];
                    }
                    in -= j * hds;
                    y++;
                }
            } else {
                if(num > 0){
                    out[y] = nums[j];
                }else{
                    out[y+1] = nums[-j];
                }
                in -= j * hds;
                y++;
            }
        }
    }else{
        out[0] = '0';
    }
    return out;
}

int getStrLen(const char str[]){
    int out = 0;
    int con = 1;
    while(con > 0){
        int u = (int)str[out];
        if (u > 0) out++;
        else con = 0;
    }
    return out;
}

int getIndex(char string[],char c){
    int out = -1;
    for (int i = 0; i < getStrLen(string); i++){
        if (string[i] == c){
            out = i;
            break;
        }
    }
    return out;
}

char * strConcat(char str1[],char str2[]){
    static char out[4096] = {};
    int len1 = getStrLen(str1);
    int len2 = getStrLen(str2);
    for (int i = 0 ; i < len1 ; i++){
        out[i] = str1[i];
    }
    for (int i = 0 ; i < len2 ; i++){
        out[len1 + i] = str2[i];
    }
    return out;
}

int strComp(char str1[],char str2[]){
    int out = -1;
    int len1 = getStrLen(str1);
    int len2 = getStrLen(str2);
    if (len1 == len2){
        for (int i = 0 ; i < len1 ; i++){
            if (str1[i] != str2[i]){
                out = i;
                break;
            }
        }
    }else{
        out = 0;
    }
    return out;
}

int strContains(char str[],char sub[]){
    int in = -1;
    for (int i = 0 ; i < getStrLen(str) ; i++){
        if (str[i] == sub[0]){
            in = i;
            for (int j = 1 ; j < getStrLen(sub) ; j++){
                if (str[in + j] != sub[j]){
                    in = -1;
                    break;
                }
            }
        }
    }
    return in;
}
char * subString(const char str[],int start,int end){
    static char out[2048] = {};
    for (int i = start,j = 0 ; i < end ; i++,j++){
        out[j] = str[i];
    }
    return out;
}

int strStartsWith(char str[],char start[]){
    int out = 1;
    int len2 = getStrLen(start);
    char * sub = subString(str,0,len2);
    if (strComp(sub,start) != -1) out = 0;
    return out;
}

int strEndsWith(char str[],char end[]){
    int out = 1;
    int len1 = getStrLen(str);
    int len2 = getStrLen(end);
    char * sub = subString(str,len1-len2,len1);
    if (strComp(sub,end) != -1) out = 0;
    return out;
}

char * strToLower(char str[]){
    static char out[4096] = {};
    char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowers[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0 ; i < getStrLen(str) ; i++){
        int ind = getIndex(uppers,str[i]);
        if (ind != -1){
            out[i] = lowers[ind];
        }else{
            out[i] = str[i];
        }
    }
    return out;
}

char * strToUpper(char str[]){
    static char out[4096] = {};
    char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowers[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0 ; i < getStrLen(str) ; i++){
        int ind = getIndex(lowers,str[i]);
        if (ind != -1){
            out[i] = uppers[ind];
        }else{
            out[i] = str[i];
        }
    }
    return out;
}

char * strReplace(char str[],char rep[],char new[]){
    static char out[4096] = {};
    int len1 = getStrLen(str);
    int ln;
    int len2 = getStrLen(rep);
    int len3 = getStrLen(new);
    int dif = len2 - len3;
    int in = strContains(str,rep);
    if (dif < 0) ln = len1 -dif;
    else ln = len1;
    for (int i = 0 ; i < len1 ; i++){
        out[i] = str[i];
    }
    if ( in != -1){
        for (int j = in,u = 0 ; j < ln ; j++ , u++){
            if (dif > 0){
                if (u < len3){
                    out[j] = new[u];
                }else{
                    out[j] = str[j+dif];
                }
            }else if (dif < 0){
                if (u < len3){
                    out[j] = new[u];
                }
                if (u == len2-1){
                    for (int n = len1 ; n > j ; n--){
                        out[n-dif] = out[n];
                    }
                }
            }else{
                if (u < len3) {
                    out[j] = new[u];
                }
            }
        }
    }
    return out;
}