// Private item replacement search; partial semantic handles and vector layout.
// NOTE: names are inferred from control flow; integrity is Item+0x1c, condition457ca0 is 100*integrity/definition+0xa8.
// rating457920 reads definition+0x50 with a modifier at+0x94; power/effect/type/category names remain placeholders; def4c4578c0 reads definition+0x4c.
struct LA5Item {int type457820() throw();int subtype457880() throw();int category4578a0() throw();int def4c4578c0() throw();int rating457920() throw();bool flagged415ee0() throw();bool excluded457d10() throw();int condition457ca0() throw();int effect457f90() throw();int power457fb0() throw();int integrity9b6bf0() throw();};
struct LA5Handle {unsigned token;LA5Handle() throw();LA5Item *operator->() const throw();bool isNull9b65d0() const throw();};
struct LA5Entity {int subtype5d1390() throw();};struct LA5EntityHandle {unsigned token;LA5Entity *operator->()const throw();};
struct LA5Items {unsigned size9b9260()const throw();LA5Handle &operator[](unsigned) throw();};
void la5_erase9d6440(LA5Items&,int&) throw();extern int la5_ba2f88[];
LA5Handle la5_select4fe3f0(LA5Handle item,LA5Items &items,LA5EntityHandle entity) throw() {
 if(item->def4c4578c0()!=1 || item->flagged415ee0() || item->excluded457d10()) return LA5Handle();
 LA5Handle result;
 for(int i=0;i<items.size9b9260();i++) if(items[i]->category4578a0()!=item->category4578a0() || items[i]->def4c4578c0()!=1) la5_erase9d6440(items,i);
 for(int i=0;i<items.size9b9260();i++) if(item->type457820()==items[i]->type457820() && item->integrity9b6bf0()>items[i]->integrity9b6bf0() && item->condition457ca0()>=items[i]->condition457ca0()+15 && (result.isNull9b65d0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];
 if(result.isNull9b65d0()) {
  for(int i=0;i<items.size9b9260();i++) if(item->effect457f90() && item->effect457f90()==items[i]->effect457f90()) {
   switch(la5_ba2f88[item->effect457f90()]) {
    case 0:if(item->power457fb0()>items[i]->power457fb0() && (result.isNull9b65d0() || result->power457fb0()>items[i]->power457fb0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];break;
    case 1:if(item->power457fb0()<items[i]->power457fb0() && (result.isNull9b65d0() || result->power457fb0()<items[i]->power457fb0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];break;
   }
  }

 if(result.isNull9b65d0()) {
  if((!item->effect457f90() || item->effect457f90()==118) && item->category4578a0()!=2) {
   bool same=item->category4578a0()==1;
   for(int i=0;i<items.size9b9260();i++) {
    if(item->category4578a0()==items[i]->category4578a0() && (!same || item->subtype457880()==items[i]->subtype457880()) && ((item->rating457920()==items[i]->rating457920() && item->integrity9b6bf0()*0.75>=items[i]->integrity9b6bf0()) || (item->rating457920()>items[i]->rating457920() && item->integrity9b6bf0()>=items[i]->integrity9b6bf0()))) {
     if(result.isNull9b65d0() || result->rating457920()>items[i]->rating457920() || (result->rating457920()==items[i]->rating457920() && result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];
    }
   }
  }

 if(result.isNull9b65d0()) {
  if(item->effect457f90()==46) for(int i=0;i<items.size9b9260();i++) {
   if(items[i]->effect457f90()==46 && item->integrity9b6bf0()*0.75+item->rating457920()>=items[i]->integrity9b6bf0()+items[i]->rating457920() && (result.isNull9b65d0() || result->integrity9b6bf0()+result->rating457920()>items[i]->integrity9b6bf0()+items[i]->rating457920())) result=items[i];
  }

 if(result.isNull9b65d0()) {
  if(item->category4578a0()==1 && item->subtype457880()-9==entity->subtype5d1390()) for(int i=0;i<items.size9b9260();i++) {
   if(items[i]->category4578a0()==1 && items[i]->subtype457880()!=item->subtype457880() && (result.isNull9b65d0() || result->integrity9b6bf0()+result->rating457920()>items[i]->integrity9b6bf0()+items[i]->rating457920())) result=items[i];
  }
 }
 }
 }
 }
 return result;
}
