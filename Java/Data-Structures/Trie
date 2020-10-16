import java.util.*;
class Trie{
    //Quick Trie Implementation modify according to needs..
    Map<Character,TrieNode> child;
    boolean isEnd;
    TrieNode(){
        child = new HashMap();
    }
    void addString(Trie root,String str){
        TrieNode r = root;
        for(char ch:str.toCharArray()){
            if(!r.child.containsKey(ch))
                r.child.put(ch,new TrieNode());
            r = r.child.get(ch);
        }
        r.isEnd = true;
    }
    boolean checkPrefix(TrieNode root,String prefix){
        TrieNode r = root;
        for(char ch : prefix.toCharArray()){
            if(!r.child.containsKey(ch))
                return false;
            r = r.child.get(ch);
        }
        return true;
    }    
}
