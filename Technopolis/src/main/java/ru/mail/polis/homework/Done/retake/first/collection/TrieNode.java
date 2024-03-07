package ru.mail.polis.homework.retake.first.collection;

public class TrieNode{
        private TrieNode[] child = new TrieNode[26];
        private boolean isEnd;
        TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++) child[i] = null;
        }

        static TrieNode root;
    public static boolean searchString(String str){
        TrieNode curr = root;
        int n = str.length();
        for(int i=0;i<n;i++){
            int idx = str.charAt(i) - 'a';
            if(curr.child[idx]== null)
                return false;
            curr = curr.child[idx];
        }
        return curr.isEnd;
    }

    public static void insertString(String str){
        TrieNode curr = root;
        int n = str.length();
        for(int i=0;i<n;i++){
            int idx = str.charAt(i) - 'a';
            if(curr.child[idx] == null)
                curr.child[idx] = new TrieNode();
            curr = curr.child[idx];
        }
        curr.isEnd = true;
    }
};