void __cdecl populate_entity_variants_menu(debug_menu_entry *entry)
{
  const mString *name; // eax
  _std::list__entity_ptr::iterator *v2; // eax
  entity **v3; // eax
  entity *v4; // eax
  const string_hash *id; // eax
  const char *v6; // eax
  entity **v7; // eax
  entity *v8; // eax
  debug_menu *v9; // [esp+Ch] [ebp-84h]
  debug_menu_entry *v10; // [esp+Ch] [ebp-84h]
  char v11[4]; // [esp+18h] [ebp-78h] BYREF
  _std::list__entity_ptr::iterator v12[2]; // [esp+1Ch] [ebp-74h] BYREF
  debug_menu_entry *v13; // [esp+24h] [ebp-6Ch]
  mString a1; // [esp+28h] [ebp-68h] BYREF
  int v15; // [esp+34h] [ebp-5Ch]
  debug_menu_entry *v16; // [esp+78h] [ebp-18h]
  _std::list__entity_ptr::iterator v17; // [esp+7Ch] [ebp-14h] BYREF
  debug_menu *v18; // [esp+80h] [ebp-10h]
  int v19; // [esp+8Ch] [ebp-4h]

  v15 = 0;
  v19 = 0;
  if ( sub_68C150() )
  {
    name = j_debug_menu_entry::get_name(entry);
    v9 = (debug_menu *)j_debug_menu::debug_menu_0(name, 1);
  }
  else
  {
    v9 = 0;
  }
  v19 = -1;
  v18 = v9;
  j_debug_menu_entry::set_submenu(entry, v9);
  j_entity::find_entities_1(256);
  sub_685846(entity::found_entities, &v17);
  while ( 1 )
  {
    v2 = sub_6A4A5C(entity::found_entities, v12);
    if ( !sub_687CAE(&v17, v2) )
      break;
    v13 = (debug_menu_entry *)sub_65CD1A(76);
    v19 = 1;
    if ( v13 )
    {
      v3 = sub_681BCE(&v17);
      v4 = j_to_pointer__entity1(v3);
      id = j_entity_base::get_id(&v4->base.base);
      v6 = j_string_hash::to_string(id);
      j_mString::from_char(&a1, v6);
      LOBYTE(v19) = 2;
      v15 |= 1u;
      v10 = j_debug_menu_entry::debug_menu_entry(v13, &a1);
    }
    else
    {
      v10 = 0;
    }
    v12[1]._Ptr = (Node__entity_ptr *)v10;
    v16 = v10;
    v19 = -1;
    if ( (v15 & 1) != 0 )
    {
      v15 &= ~1u;
      j_mString::finalize(&a1);
    }
    j_debug_menu_entry::set_game_flags_handler(v16, j_populate_variants_menu);
    v7 = sub_681BCE(&v17);
    v8 = sub_694A7B((entity_base_vhandle *)v7);
    j_debug_menu_entry::set_data(v16, v8);
    j_debug_menu_entry::set_submenu(v16, 0);
    j_debug_menu::add_entry(v18, v16);
    sub_67E91F(&v17, v11, 0);
  }
}

void __cdecl create_entity_variant_menu(debug_menu *parent)
{
  debug_menu_entry *v1; // [esp+Ch] [ebp-6Ch]
  debug_menu_entry *v2; // [esp+14h] [ebp-64h]
  mString a1; // [esp+18h] [ebp-60h] BYREF
  int v4; // [esp+24h] [ebp-54h]
  debug_menu_entry *v5; // [esp+68h] [ebp-10h]
  int v6; // [esp+74h] [ebp-4h]

  v4 = 0;
  v2 = (debug_menu_entry *)sub_65CD1A(76);
  v6 = 0;
  if ( v2 )
  {
    j_mString::from_char(&a1, "Entity Variants");
    LOBYTE(v6) = 1;
    v4 |= 1u;
    v1 = j_debug_menu_entry::debug_menu_entry(v2, &a1);
  }
  else
  {
    v1 = 0;
  }
  v5 = v1;
  v6 = -1;
  if ( (v4 & 1) != 0 )
  {
    v4 &= ~1u;
    j_mString::finalize(&a1);
  }
  j_debug_menu_entry::set_submenu(v5, 0);
  j_debug_menu_entry::set_game_flags_handler(v5, j_populate_entity_variants_menu);
  j_debug_menu::add_entry(parent, v5);
}
