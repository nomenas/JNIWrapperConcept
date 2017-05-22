package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 18/04/2017.
 */

public class BaseClass extends Object {
    public BaseClass() {create();};

    public final native int baseClassMethod();

    protected native void create();
    protected native void delete();
}
