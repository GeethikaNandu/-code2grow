#include <stdio.h>

int main() {
    int n, days, type, i;
    char bf, wifi, gym;
    float rate, add, total, gst, disc, final, revenue=0, high=0, low=0;

    printf("Enter total customers: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++) {
        printf(" Customer %d \n", i);
        printf("Room type (1-Deluxe,2-Super Deluxe,3-Suite): ");
        scanf("%d", &type);
        printf("Days: "); scanf("%d",&days);
        printf("Breakfast (Y/N): "); scanf(" %c",&bf);
        printf("Wi-Fi (Y/N): "); scanf(" %c",&wifi);
        printf("Gym (Y/N): "); scanf(" %c",&gym);

        if(type==1) rate=2500;
        else if(type==2) rate=4000;
        else rate=6000;

        add=0;
        if(bf=='Y'||bf=='y') add+=300;
        if(wifi=='Y'||wifi=='y') add+=100;
        if(gym=='Y'||gym=='y') add+=200;

        total=(rate+add)*days;
        disc=(total>10000)? total*0.10:0;
        total-=disc;
        gst=total*0.12;
        final=total+gst;

        printf("Final Bill: ₹%.2f\n",final);

        revenue+=final;
        if(i==1){high=low=final;}
        if(final>high) high=final;
        if(final<low) low=final;
    }

    printf(" Summary\nTotal Revenue: ₹%.2f\nHighest Bill: ₹%.2f\nLowest Bill: ₹%.2f\n",revenue,high,low);
    return 0;
}
