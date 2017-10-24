package com.godhc.usaco;

import java.io.*;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.StringTokenizer;

/*
ID: 10isapr1
LANG: JAVA
TASK: gift1
problem = Task 'gift1': Greedy Gift Givers
 */
public class gift1 {
    public static void main(String [] args) throws IOException{
        //BufferedReader br = new BufferedReader(new FileReader("gift1.in"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String npString = br.readLine();
        Integer np = Integer.parseInt(npString);


        Map<String, Integer> friends = new LinkedHashMap<>();

        // read np friends
        for(int i =0; i < np; i++) {
            String currentFriend = br.readLine();
            friends.put(currentFriend, 0);
        }

        // process np groups
        for (int group = 0; group < np; group++) {
            String giftGiver = br.readLine();
            String valueAndReceiversCount = br.readLine();

            StringTokenizer st = new StringTokenizer(valueAndReceiversCount);
            Integer giftGiverInitialValue = Integer.parseInt(st.nextToken());
            Integer receiversCount = Integer.parseInt(st.nextToken());


            // set the gift giver initial value in friends.
            Integer giftGiverAccountValue = friends.get(giftGiver);
            giftGiverAccountValue -= giftGiverInitialValue;
            friends.replace(giftGiver, giftGiverAccountValue);


            // find the amount that needs to be given to each receiver
            Integer perReceiverAmount = 0;

            if (receiversCount > 0)
                perReceiverAmount = giftGiverInitialValue/receiversCount;

            // find the remaining amount that was not given and credit it to giftGiver
            Integer amountLeftForGiftGiver = 0;

            if(receiversCount > 0)
                amountLeftForGiftGiver = giftGiverInitialValue % receiversCount;

            giftGiverAccountValue += amountLeftForGiftGiver;
            friends.replace(giftGiver, giftGiverAccountValue);

            for (int receiver = 0; receiver < receiversCount; receiver++){
                String receiverName = br.readLine();
                Integer receiverPreviousValue = friends.get(receiverName);
                friends.replace(receiverName, receiverPreviousValue + perReceiverAmount);
            }
        }

        // display total remaining amounts
        for (Map.Entry<String, Integer> entry: friends.entrySet()) {
            String friend = entry.getKey();
            Integer friendsAmount = entry.getValue();
            print(friend + " " + friendsAmount);
        }

    }

    private  static void print(String val) throws IOException {
        System.out.println((val));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out", true)));
        pw.println(val);
        pw.close();
    }
}
