import java.util.*;

class Solution {
  /*
          class Node
                  public  int frequency; // the frequency of this tree
          public  char data;
          public  Node left, right;

  */
  void decode(String s, Node root) {
    StringBuilder sb = new StringBuilder();
    Node itr = root;
    int i = 0;

    while (i < s.length()) {
      itr = root;
      while (itr.data == 0) {
        if (s.charAt(i) == '1') {
          itr = itr.right;
        } else {
          itr = itr.left;
        }
        ++i;
      }
      sb.append(itr.data);
    }

    System.out.println(sb.toString());
  }
}