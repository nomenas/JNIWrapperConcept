package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 14/04/2017.
 */

public class SingleInheritanceExt extends SingleInheritance {
    public SingleInheritanceExt() {create();};

    protected native void create();
    protected native void delete();
}
