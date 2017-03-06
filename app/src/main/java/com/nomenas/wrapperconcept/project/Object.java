package com.nomenas.wrapperconcept.project;

abstract class Object {
    private long reference = 0;
    private boolean isOwner = false;

    public void setReference(long reference, boolean takeOwnership) {
        this.reference = reference;
        this.isOwner = takeOwnership;
    }

    public long getReference() {
        return reference;
    }

    protected void finalize() {
        if (isOwner) {
            delete();
        }
    }

    protected abstract void delete();
}
