class InvalidStringException extends Exception{
    public InvalidStringException(String str){
        super(str);
    }
}

class ArrayToList implements MyList{
    ArrayList<String> arrayToList;
    ArrayToList(){
        arrayToList=new ArrayList<>();
    }
    void convert(String[] a){
        for(String s:a){
            System.out.println("I have added the string: "+s+" at index: "+this.arrayToList.size());
            this.arrayToList.add(s);
        }
    }
    void replace(int idx){
        String s = arrayToList.get(idx);
        System.out.println("I have replaced the string: "+s+" with a null string");
        arrayToList.set(idx,"");
    }
    ArrayList<String> compact(){
        ArrayList<String> res = new ArrayList<>();
        for(String s:arrayToList){
            if(!("".equals(s))){
                res.add(s);
            }
        }
        return res;
    }
}
