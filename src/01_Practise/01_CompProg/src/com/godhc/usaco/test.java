/*
ID: 10isapr1
LANG: JAVA
TASK: test
 */
package com.godhc.usaco;
import java.io.*;
import java.util.StringTokenizer;

public class test {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("test.in"));

        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Integer first = Integer.parseInt(st.nextToken());
        Integer second = Integer.parseInt(st.nextToken());
        pw.println(first+second);
        pw.close();
    }
}
