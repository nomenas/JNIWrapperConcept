package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 18/04/2017.
 */

public class Integer extends Object {
    public Integer() {create(0);};
    public Integer(int value) {create(value);};

    public final native int value();

    protected final native void create(int value);
    protected native void delete();
}
