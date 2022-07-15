class Solution
{
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
   static bool comp(struct meeting m1 , struct meeting m2){
        if(m1.end < m2.end){
            return true;
        }else if(m1.end > m2.end){
            return false;
        }else if(m1.pos < m2.pos){
            return true;
        }
        return false;
    }
    

    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        
        struct meeting arr[n];
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i;
        }
        // sort the arr of meeting type
        sort(arr , arr+n , comp);
        
        int meetCount = 1;
        int endTime = arr[0].end;
        
        for(int i = 1; i < n; i++){
            if(arr[i].start > endTime){
                endTime = arr[i].end;
                meetCount++;
            }
        }
        return meetCount;
    }
};
