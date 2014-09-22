        int InsertSort(){//无链表头的链表插入排序
                node *insert = head->pNext;
                head->pNext=NULL;
                Node *pre;
                while(insert){
                        node * nInsert = insert->pNext;
                        node *cur=head;
                        while(cur!=NULL&&(cur->value<insert->value)){
                                pre=cur;
                                cur=cur->pNext;
                        }
                        if(cur==head){//插在第一个节点之前
                            head = insert;
                        }else{//pre是Cur的前驱，且pre<insert然后insert<cur或者cur为NULL
                                pre->pNext=insert;
                        }
                        insert->pNext=cur;
                        insert=nInsert;
                }
                return 0;
        }
        int InsertSortwithNode(){//带链表头的插入排序
                node * insert = head->pNext;
                head->pNext=NULL;//空链表
                //Node * pre;
                while(insert){
                        node *pre=head;//前驱节点
                        node *cur=head->pNext;
                        while(cur!=NULL&&(cur->value<insert->value)){
                                pre = cur;
                                cur = cur->pNext;//后继节点
                        }
                        Node * nInsert = insert->pNext;
                        pre->pNext=insert;
                        insert->pNext=cur;
                        insert=nInsert;
                }
                return 0;
        }