#pragma once

#include <optional>
#include <string>

#include <libtorrent/extensions.hpp>
#include <libtorrent/settings_pack.hpp>
#include <libtorrent/storage_defs.hpp>

typedef std::function<std::shared_ptr<libtorrent::torrent_plugin>(libtorrent:: torrent_handle const&, libtorrent::client_data_t)> lt_plugin;

namespace porla
{
    class Config
    {
    public:
        struct Preset
        {
            std::optional<int>                        download_limit;
            std::optional<int>                        max_connections;
            std::optional<int>                        max_uploads;
            std::optional<std::string>                save_path;
            std::optional<libtorrent::storage_mode_t> storage_mode;
            std::optional<int>                        upload_limit;
        };

        std::optional<std::string>            config_file;
        std::optional<std::string>            db;
        std::optional<std::string>            http_auth_token;
        std::optional<std::string>            http_host;
        std::optional<uint16_t>               http_port;
        std::optional<std::string>            log_level;
        std::map<std::string, Preset>         presets;
        std::optional<std::vector<lt_plugin>> session_extensions;
        libtorrent::settings_pack             session_settings;
        std::optional<int>                    supervised_interval;
        std::optional<pid_t>                  supervised_pid;
        std::optional<int>                    timer_dht_stats;
        std::optional<int>                    timer_session_stats;
        std::optional<int>                    timer_torrent_updates;

        static Config Load(int argc, char* argv[]);
    };
}
