class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {  
        PriorityQueue<int[]>pq = new PriorityQueue<>((a,b)->{
            if(a[0]==b[0]) return a[1] - b[1]; // minheap;
            return b[0] - a[0];//maxheap a after b -> a is greater;
        });
        int n = nums.length;
        int []ans=new int[n-k+1];
        int index=0;
        int i;
        for(i=0;i<k;i++){
            pq.offer(new int[]{nums[i],i});
        }
        ans[index++] = pq.peek()[0];
        while(i<n){
            pq.offer(new int[]{nums[i],i});
            while(!pq.isEmpty() && pq.peek()[1] <= i-k){
                pq.poll();
            }
            ans[index++] = pq.peek()[0];
            i++;
    
    }
    return ans;
}
};