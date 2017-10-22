package com.godhc.codebrunch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String name = br.readLine();

        ArrayList<Character> initials = new ArrayList<>();
        for (int i = 0; i < name.length(); i++) {
            if (Character.isUpperCase(name.charAt(i))){
                initials.add(name.charAt(i));
            }
        }

        System.out.printf("The initials are: %s", getStringRepresentation(initials));
    }

    private static String getStringRepresentation(ArrayList<Character> string) {
        StringBuilder sb  = new StringBuilder(string.size());
        for(Character character: string) {
            sb.append(character);
        }
        return  sb.toString();
    }
}
