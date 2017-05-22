package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 10/03/2017.
 */

public class CallbackTester extends Object {
    public CallbackTester(int value) {
        create(value);
    }

    public final native void do_callback(Callback callback);
    public final native void do_callback(LambdaCallback callback);

    protected CallbackTester() {};
    protected final native void create(int value);
    protected native void delete();
}
