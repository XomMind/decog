// Private item replacement search; partial semantic handles and vector layout.
// NOTE: names are inferred from control flow; integrity is Item+0x1c, condition457ca0 is 100*integrity/definition+0xa8.
// rating457920 reads definition+0x50 with a modifier at+0x94; power/effect/type/category names remain placeholders; def4c4578c0 reads definition+0x4c.
struct LA6Modifier {char pad[0x2c];int value;};
struct LA6Definition {char pad[0x128];int value128;char tail[0x74];LA6Modifier *modifier1a0;};
struct LA6Item {LA6Definition *definition9b4350() throw();int value45cb30() throw();int type457820() throw();int subtype457880() throw();int category4578a0() throw();int def4c4578c0() throw();int rating457920() throw();bool flagged415ee0() throw();bool excluded457d10() throw();int condition457ca0() throw();int effect457f90() throw();int power457fb0() throw();int integrity9b6bf0() throw();};
struct LA6Handle {unsigned token;LA6Handle() throw();LA6Item *operator->() const throw();bool isNull9b65d0() const throw();};
struct LA6Entity {int subtype5d1390() throw();};struct LA6EntityHandle {unsigned token;LA6Entity *operator->()const throw();};
struct LA6Items {unsigned size9b9260()const throw();LA6Handle &operator[](unsigned) throw();};
void la6_erase9d6440(LA6Items&,int&) throw();extern int la6_ba2f88[];
struct LA6Ints {int &operator[](unsigned) throw();};extern LA6Ints la6_cf4830;
struct LA6Parts {bool linked4a9b10(LA6Handle) throw();};extern LA6Parts *la6_cec088;
LA6Handle la6_select4fd9e0(LA6Handle item,LA6Items &items,bool player) throw() {
 if(item->def4c4578c0()!=1 || ((item->flagged415ee0() || item->excluded457d10()) && player && la6_cf4830[item->type457820()]!=0)) return LA6Handle();
 LA6Handle result;
 for(int i=0;i<items.size9b9260();i++) if(items[i]->category4578a0()!=item->category4578a0() || items[i]->def4c4578c0()!=1 || (player && la6_cec088->linked4a9b10(items[i]))) la6_erase9d6440(items,i);
 for(int i=0;i<items.size9b9260();i++) if(item->type457820()==items[i]->type457820() && item->integrity9b6bf0()>items[i]->integrity9b6bf0() && (item->effect457f90()!=124 || item->value45cb30()>=items[i]->value45cb30()) && (result.isNull9b65d0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];
 if(result.isNull9b65d0() && (!player || la6_cf4830[item->type457820()]!=0)) {
  for(int i=0;i<items.size9b9260();i++) if(item->effect457f90() && item->effect457f90()==items[i]->effect457f90() && (!player || la6_cf4830[items[i]->type457820()]!=0)) {
   if(item->effect457f90()==124) {
    if(item->type457820()==items[i]->type457820() && item->value45cb30()>items[i]->value45cb30() && (result.isNull9b65d0() || result->value45cb30()>items[i]->value45cb30() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];
   } else {
    switch(la6_ba2f88[item->effect457f90()]) {
     case 0:if(item->power457fb0()>items[i]->power457fb0() && (result.isNull9b65d0() || result->power457fb0()>items[i]->power457fb0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];break;
     case 1:if(item->power457fb0()<items[i]->power457fb0() && (result.isNull9b65d0() || result->power457fb0()<items[i]->power457fb0() || result->integrity9b6bf0()>items[i]->integrity9b6bf0())) result=items[i];break;
    }
   }
  }
  if(result.isNull9b65d0()) {
   if((!item->effect457f90() || item->effect457f90()==118) && item->category4578a0()!=2) {
    for(int i=0;i<items.size9b9260();i++) {
     if(item->subtype457880()==items[i]->subtype457880() || (item->category4578a0()==0 && items[i]->category4578a0()==0)) {
      if((item->subtype457880()<20 || (item->definition9b4350()->modifier1a0?item->definition9b4350()->modifier1a0->value:item->definition9b4350()->value128)==(items[i]->definition9b4350()->modifier1a0?items[i]->definition9b4350()->modifier1a0->value:items[i]->definition9b4350()->value128)) && item->integrity9b6bf0()>items[i]->integrity9b6bf0() && item->rating457920()>=items[i]->rating457920() && (result.isNull9b65d0() || result->rating457920()>items[i]->rating457920() || (result->rating457920()==items[i]->rating457920() && result->integrity9b6bf0()>items[i]->integrity9b6bf0()))) result=items[i];
     }
    }
   }
   if(result.isNull9b65d0()) {
    if(item->effect457f90()==46) for(int i=0;i<items.size9b9260();i++) {
     if(items[i]->effect457f90()==46 && item->integrity9b6bf0()+item->rating457920()>items[i]->integrity9b6bf0()+items[i]->rating457920() && (result.isNull9b65d0() || result->integrity9b6bf0()+result->rating457920()>items[i]->integrity9b6bf0()+items[i]->rating457920())) result=items[i];
    }
   }
  }
 }
 return result;
}
