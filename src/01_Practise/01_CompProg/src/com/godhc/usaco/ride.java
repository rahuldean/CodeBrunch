package com.godhc.usaco;

import java.io.*;
import java.util.HashMap;

/*
ID: 10isapr1
LANG: JAVA
TASK: ride

problem = Your Ride Is Here
 */
public class ride {
    public static void main(String [] args)  throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("ride.in"));
        String cometName = br.readLine();
        String groupName = br.readLine();

        System.out.println(cometName + " " + groupName);
        Integer cometNameValue = 1;
        for (int i = 0; i < cometName.length(); i++) {
            cometNameValue *=  getIntegerEquivalent(cometName.charAt(i));
        }

        Integer groupNameValue = 1;
        for(int j = 0; j < groupName.length(); j++) {
            groupNameValue *= getIntegerEquivalent(groupName.charAt(j));
        }

        if( (cometNameValue % 47) == (groupNameValue % 47))
            print("GO");
        else
            print("STAY");

    }

    private static void print(String val)  throws IOException{
        System.out.println(val);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
        pw.println(val);
        pw.close();
    }
    private static Integer getIntegerEquivalent(Character c) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        hashMap.put('A', 1);
        hashMap.put('B', 2);
        hashMap.put('C', 3);
        hashMap.put('D', 4);
        hashMap.put('E', 5);

        hashMap.put('F', 6);
        hashMap.put('G', 7);
        hashMap.put('H', 8);
        hashMap.put('I', 9);
        hashMap.put('J', 10);

        hashMap.put('K', 11);
        hashMap.put('L', 12);
        hashMap.put('M', 13);
        hashMap.put('N', 14);
        hashMap.put('O', 15);

        hashMap.put('P', 16);
        hashMap.put('Q', 17);
        hashMap.put('R', 18);
        hashMap.put('S', 19);
        hashMap.put('T', 20);

        hashMap.put('U', 21);
        hashMap.put('V', 22);
        hashMap.put('W', 23);
        hashMap.put('X', 24);
        hashMap.put('Y', 25);
        hashMap.put('Z', 26);

        return hashMap.get(c);
    }
}
