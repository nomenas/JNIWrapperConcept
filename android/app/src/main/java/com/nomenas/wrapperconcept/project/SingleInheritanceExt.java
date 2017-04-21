package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 14/04/2017.
 */

public class SingleInheritanceExt extends SingleInheritance {
    public SingleInheritanceExt() {create();};

    public native int method2(int value);

    protected native void create();
    protected native void delete();
}
