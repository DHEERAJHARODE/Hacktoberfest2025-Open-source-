//Problem Link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000433085/0000000000432fe1

#include <stdio.h>
#include<math.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
// Do not use an approximation - it won't be good enough
// with the large numbers involved. 

const double golden = (1 + sqrt(5)) / 2;

int main(void) {
	int tc;
	scanf("%d",&tc);
    for (int i = 1; i <= tc; i++) {
        double a1, a2, b1, b2;
        scanf("%lf %lf %lf %lf",&a1 ,&a2 ,&b1 ,&b2 );
        long long ans = 0;

        // Remember to account for symmetry when working through the
        // conditionals and counting in the code below.

        for (int b = b1; b <= b2; b++) {
            if (floor(golden * b) < a1 || floor((golden - 1) * b) > a2)
                
                // When either the lower threshold is below a1 or the upper threshold is above a2,
                // all games are winning

                ans += (a2 - a1 + 1);
            else {

                // When the thresholds intercept the (a1,a2) interval,
                // we have to explicitly count the # of winning games.

                ans += max(0.0, a2 - floor(golden * b));
                ans += max(0.0, ceil((golden - 1) * b) - a1);
            }
        } 

        printf("Case #%d: %lld\n",i,ans);
    }
}
