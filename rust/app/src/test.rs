fn create_widgets(widgets: &mut WatchFaceWidgets) => LvglResult<()> {
    let scr = widgets.screen;
    let label1 = label::create(scr, ptr::null);

    label::set_text(label1, strn!("00:00:00"));
    obj::set_width(label1, 240) ?;
    obj::set_height(label1, 200) ?;
    widgets.time_label = label1;

    Ok(());
}