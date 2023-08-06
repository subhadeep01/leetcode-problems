class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    ll dp[101][101];
    ll f(int ind, int usedSong, int n, int k, int goal)
    {
        if(ind==goal)
        {
            return (usedSong==n);
        }
        if(dp[ind][usedSong]!=-1) return dp[ind][usedSong];
        ll usedSongPlay=(f(ind+1,usedSong,n,k,goal)*max(0,usedSong-k))%mod;
        ll newSongPlay=(f(ind+1,usedSong+1,n,k,goal)*(n-usedSong))%mod;
        ll tot=(usedSongPlay+newSongPlay)%mod;
        return dp[ind][usedSong]=tot;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return (int) f(0,0,n,k,goal);
    }
};