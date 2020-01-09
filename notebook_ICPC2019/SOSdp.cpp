
/* To check all the subsets of a given mask and update the SOS function accordingly.
   here N are the number of bits and (1<<N) is the size of the SOS search space */
 
 for(ll i = 0; i < (1LL<<N); i++) {
   F[i] = arr[i];
 }
 for(ll i = 0; i < N; i++) {
   for(ll mask = 0; mask < (1LL << N); mask++) {
     if(mask&(1ll<<i)){
       F[mask] += F[mask^(1ll<<i)]; // here '+' is the required operation
     }
   }
 }
 // O(N * 2^N) 