package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 18/04/2017.
 */

public class SmartPointers {
    public static native Integer createRowInteger(int value);
    public static native Integer createSharedInteger(int value);
    public static native Integer createUniqueInteger(int value);

    public static native Integer sumRow(Integer arg1, Integer arg2);
    public static native Integer sumShared(Integer arg1, Integer arg2);
    public static native Integer sumUnique(Integer arg1, Integer arg2);
}
