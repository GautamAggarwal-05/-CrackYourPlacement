class Solution {
public:
    int nthUglyNumber(int n) {
        //1,2,3,4,5,6,8,9,10,12,15...

        if(n<=0)
        {
            return 0;
        }

        vector<int>v(n);
        //first num is 1
        v[0]=1;

        int a=0; //multiple of 2
        int b=0; //multiple of 3
        int c=0; //multiple of 5

        for(int i=1;i<n;i++)
        {
            //finding smallest multiple
            int num=min({v[a]*2,v[b]*3,v[c]*5});
            //int num=min((v[a]*2,v[b]*3),v[c]*5);
            v[i]=num;

            if(num==v[a]*2)
            {
                a++;
            }
            if(num==v[b]*3)
            {
                b++;
            }
            if(num==v[c]*5)
            {
                c++;
            }
        }
        return v[n-1];

    }
};