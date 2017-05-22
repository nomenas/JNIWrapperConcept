package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 22/05/2017.
 */

public class SingleInheritanceCustom extends SingleInheritance {
    public SingleInheritanceCustom() {create();};

    public int java_overridable(){
        return 100;
    }

    protected native void create();
    protected native void delete();
}
