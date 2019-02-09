#include <iostream>

#include "find_all_public_folder.h"

bool FindProjectIncludeDirectory::set_base_directory(const std::string &path, bool is_engine_dir) {
    if (!boost::filesystem::is_directory(path)) {
        std::cerr << "Cannot find project path:" << path << std::endl;
        return false;
    }

    boost::filesystem::path temp_path(path);
    if (is_engine_dir) {
        m_engine_directory = temp_path;
    } else {
        m_project_directory = temp_path;
    }

    return true;
}

bool FindProjectIncludeDirectory::set_project_directory(const std::string &path) {
    return set_base_directory(path, false);
}

bool FindProjectIncludeDirectory::set_unreal_engine_directory(const std::string &path) {
    return set_base_directory(path, true);
}

std::string FindProjectIncludeDirectory::get_include_directory() {
    std::string engine_include(get_engine_include_directory());
    std::string project_include(get_project_include_directory());
    std::string editor_include(get_editor_include_directory());

    return engine_include + project_include + editor_include;
}

std::string FindProjectIncludeDirectory::get_editor_include_directory() {
    std::string editor_include("");

    if (m_engine_directory.empty()) {
        return editor_include;
    }

    std::string indent = "                \"";
    std::string end_indent = "\",\n";

    boost::filesystem::path editor_runtime_path(m_engine_directory);
    editor_runtime_path += "\\Engine\\Source\\Editor";

    for (boost::filesystem::directory_entry &dir_entry: boost::filesystem::directory_iterator(editor_runtime_path)) {
        boost::filesystem::path single_path(dir_entry.path());
        single_path += "\\Public";

        if (boost::filesystem::is_directory(single_path)) {
            editor_include += indent;
            editor_include += single_path.string();
            editor_include += end_indent;

            for (boost::filesystem::directory_entry &temp_entry: boost::filesystem::directory_iterator(single_path)) {
                boost::filesystem::path sub_path(temp_entry.path());

                if (!boost::filesystem::is_directory(sub_path)) {
                    continue;
                }

                editor_include += indent;
                editor_include += sub_path.string();
                editor_include += end_indent;
            }
        }

        boost::filesystem::path single_path2(dir_entry.path());
        single_path2 += "\\Classes";
        if (boost::filesystem::is_directory(single_path2)) {
            editor_include += indent;
            editor_include += single_path2.string();
            editor_include += end_indent;
        }
    }
    
    return editor_include;
}

std::string FindProjectIncludeDirectory::get_engine_include_directory() {
    std::string engine_include("");

    if (m_engine_directory.empty()) {
        return engine_include;
    }

    std::string indent = "                \"";
    std::string end_indent = "\",\n";

    // find engine runtime library directory from engine root directory
    boost::filesystem::path engine_runtime_path(m_engine_directory);
    engine_runtime_path += "\\Engine\\Source\\RunTime";

    for (boost::filesystem::directory_entry &dir_entry: boost::filesystem::directory_iterator(engine_runtime_path)) {
        boost::filesystem::path single_path(dir_entry.path());
        single_path += "\\Public";
        if (boost::filesystem::is_directory(single_path)) {
            engine_include += indent;
            engine_include += single_path.string();
            engine_include += end_indent;

            for (auto &dir_entry : boost::filesystem::directory_iterator(single_path))
            {
                boost::filesystem::path sub_path(dir_entry.path());
                if (boost::filesystem::is_directory(sub_path))
                {
                    engine_include += indent;
                    engine_include += sub_path.string();
                    engine_include += end_indent;
                }
            }
        }

        boost::filesystem::path single_path2(dir_entry.path());
        single_path2 += "\\Classes";
        if (boost::filesystem::is_directory(single_path2)) {
            engine_include += indent;
            engine_include += single_path2.string();
            engine_include += end_indent;
        }
    }
    return engine_include;
}

std::string FindProjectIncludeDirectory::get_project_include_directory() {
    std::string project_include = "";

    if (m_project_directory.empty()) {
        return project_include;
    }

    std::string indent = "                \"";
    std::string end_indent = "\",\n";

    boost::filesystem::path project_path(m_project_directory);
    for (boost::filesystem::directory_entry &dir_entry: boost::filesystem::directory_iterator(project_path)) {
        boost::filesystem::path single_path(dir_entry.path());
        single_path += "\\Inc";
        if (!boost::filesystem::is_directory(single_path)) {
            continue;
        }

        for (auto &sub_dir_entry: boost::filesystem::directory_iterator(single_path)) {
            project_include += indent;
            project_include += sub_dir_entry.path().string();
            project_include += end_indent;
        }
    }
    return project_include;
}