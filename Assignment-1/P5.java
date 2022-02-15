package pk;
//Ahmed Essam eldin Abd-elfattah Ibrahim    CS-S2   20190050
import java.util.Random;
class Node{
    public int value;
    public Node right;
    public Node left;
    public Node upper;
    public Node down;


    public Node(int key){
        this.value = key;
        this.right = null;
        this.left = null;
        this.down = null;
        this.upper = null;
    }
}
public class SkipList {


    private Node head, tail;
    private static int steps;

    private final int minValue = Integer.MIN_VALUE;
    private final int maxValue = Integer.MAX_VALUE;
    private int layers ;

    public Random random = new Random();

    public SkipList(){
        head = new Node(minValue);
        tail = new Node(maxValue);
        head.right = tail;
        tail.left = head;
        layers=0;
    }
    Node  findPostion(int key , int step)
    {
        Node n = head;
        step = 0;

        while (n.down != null){
            n =n.down;

            while (key >= n.right.value){
                n = n.right;
                step++;
            }
        }

        if(n.value != key){
            step = -1;
        }
        return n;
    }

    public int search(int key){
        Node n = head;
        steps = 0;
        findPostion(key , steps);
        return steps;
    }



    public void insert (int key){
        Node position = findPostion(key , steps);
        Node q;

        int level = -1;
        if (position.value == key){
            return ;
        }

        do{
            level++;

            if (level >= this.layers){
                this.layers++;
                addEmptyLevel();
            }

            q = position;

            while (position.upper == null){ // getting the closest smaller node from the level above
                position = position.left;
            }
            position = position.upper;

            q = insertAfterAbove(position, q ,key);


        }while(random.nextBoolean()); // coin flips to head we need to go up level


    }



    private void addEmptyLevel(){
        Node newHead = new Node(minValue);
        Node newTail = new Node(maxValue);

        newHead.right = newTail;
        newHead.down = this.head;
        newTail.left = newHead;
        newTail.down = this.tail;

        head.upper = newHead;
        tail.upper = newTail;

        this.head = newHead;
        this.tail = newTail;
    }
    private Node insertAfterAbove(Node position, Node q, int key){
        Node newNode = new Node(key);
        Node nodeBeforeNewNode = position.down.down; // getting contact with lower level, could be null

        setBeforeAndAfterReferences(q, newNode);
        setAboveAndBelowReferences(position, key, newNode, nodeBeforeNewNode);

        return newNode;

    }
    private void setBeforeAndAfterReferences(Node q, Node newNode){ // set references for entered node
        newNode.right = q.right;
        newNode.left = q;
        q.right.left = newNode;
        q.right = newNode;
    }
    private void setAboveAndBelowReferences(Node position, int key, Node newNode, Node nodeBeforeNewNode){ // set references for entered node
        if(nodeBeforeNewNode != null){ // lower level exists
            while (true){
                if (nodeBeforeNewNode.right.value != key){
                    nodeBeforeNewNode = nodeBeforeNewNode.right;
                }
                else{
                    break;
                }
            }
            newNode.down = nodeBeforeNewNode.right;
            nodeBeforeNewNode.right.upper = newNode;
        }

        if(position != null){
            if(position.right.value == key){
                newNode.upper = position.right;
            }
        }
    }

    private int getLayers(){
        return layers;
    }

    private void printLayer(int layer){
        Node curr  = head;
        for (int i = 0; i < layers - layer; i++){
            curr = curr.down;
        }
        while (curr.right.right.value != maxValue){
            System.out.print(curr.right.value+",");
            curr = curr.right;
        }
        System.out.println(curr.right.value);



    }


    private void delete(int key){
        Node rmNode = findPostion(key , steps);

        if (rmNode.value != key){ // node doesn't exist
            return ;
        }

        

        while(rmNode != null){
            Node before = rmNode.left ,  after = rmNode.right;
            before.right = after;
            after.left = before;
            if(rmNode.upper != null){
                rmNode = rmNode.upper;
            }else{
                break;
            }
        }

    }
    


    public static void  main(String[] args){
        SkipList sl = new SkipList();
        sl.insert(2);
        sl.insert(10);
        sl.insert(15);
        sl.insert(16);
        sl.insert(31);
        sl.insert(71);
        sl.insert(89);
        sl.insert(91);
        sl.insert(96);
        sl.delete(15);

        System.out.println(sl.getLayers());

        for (int i = 0; i <sl.layers; i++){
            sl.printLayer(i);
            System.out.println();
        }

    }

}
