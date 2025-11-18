 #include <stdio.h>

#define MAX 20

int id[MAX], qty[MAX], price[MAX], n = 0;

// Function prototypes
void add();
void search();
void update();
void rack();
void stock();
void display();

int main() {
    int ch;
    while (1) {
        printf("\n1.Add  2.Search  3.Update  4.RackReport  5.StockValue  6.Display  7.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:add(); break;
            case 2:search(); break;
            case 3:update(); break;
            case 4:rack(); break;
            case 5:stock(); break;
            case 6:display(); break;
            case 7:return 0;
            default: printf("Invalid!\n");
        }
    }
}

// 1. Add Product
void add() {
    if (n >= MAX) { printf("Full!\n"); return; }

    int pid, q, p;
    printf("ID Qty Price: ");
    scanf("%d %d %d", &pid, &q, &p);

    // duplicate check
    for (int i=0;i<n;i++) 
        if (id[i]==pid){ printf("Duplicate!\n"); return; }

    if (q<=0 || p<=0){ printf("Invalid!\n"); return; }

    id[n]=pid; qty[n]=q; price[n]=p; 
    n++;
    printf("Added!\n");
}

// 2. Search Product
void search() {
    int pid;
    printf("Enter ID: ");
    scanf("%d",&pid);

    for (int i=0;i<n;i++)
        if (id[i]==pid){
            printf("ID:%d Qty:%d Price:%d\n",id[i],qty[i],price[i]);
            return;
        }
    printf("Not Found!\n");
}

// 3. Update Quantity
void update() {
    int pid, c, val;
    printf("Enter ID: ");
    scanf("%d",&pid);

    for (int i=0;i<n;i++)
        if (id[i]==pid){
            printf("1.Inc 2.Dec : ");
            scanf("%d",&c);
            printf("Value: ");
            scanf("%d",&val);

            if (c==1) qty[i]+=val;
            else if (c==2 && qty[i]-val>=0) qty[i]-=val;
            else { printf("Invalid!\n"); return; }

            printf("Updated!\n");
            return;
        }
    printf("Not Found!\n");
}

// 4. Rack Report (3x3)
void rack() {
    int r[3][3], max, min, maxr=0,maxc=0,minr=0,minc=0, tot=0;

    printf("Enter 9 rack values:\n");
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            scanf("%d",&r[i][j]);

    max=min=r[0][0];

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++){
            int v=r[i][j];
            tot+=v;
            if (v>max){ max=v; maxr=i; maxc=j; }
            if (v<min){ min=v; minr=i; minc=j; }
        }

    printf("Max=%d at (%d,%d)\n",max,maxr,maxc);
    printf("Min=%d at (%d,%d)\n",min,minr,minc);
    printf("Total=%d\n",tot);
}

// 5. Stock Values
void stock() {
    long long sv, tot=0, max=-1, min=1e18;
    int maxID=0, minID=0;

    printf("ID Qty Price Value\n");

    for (int i=0;i<n;i++){
        sv = (long long)qty[i]*price[i];
        printf("%d %d %d %lld\n",id[i],qty[i],price[i],sv);

        tot += sv;

        if (sv>max){ max=sv; maxID=id[i]; }
        if (sv<min){ min=sv; minID=id[i]; }
    }

    printf("MaxValue ID=%d Val=%lld\n",maxID,max);
    printf("MinValue ID=%d Val=%lld\n",minID,min);
    printf("Total Warehouse Value=%lld\n",tot);
}

// 6. Display All
void display() {
    printf("ID Qty Price\n");
    for (int i=0;i<n;i++)
        printf("%d %d %d\n",id[i],qty[i],price[i]);
}
