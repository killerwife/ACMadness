
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 01/21/2016 18:29:27
-- Generated from EDMX file: C:\GitHubCode\C#\WCFWPFApp\SharedComponents\ChatData.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [potst_KvasnovskyPeter556232Db];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------


-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[ChatDataSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ChatDataSet];
GO
IF OBJECT_ID(N'[dbo].[ChatUsersSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ChatUsersSet];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'ChatDataSet'
CREATE TABLE [dbo].[ChatDataSet] (
    [Id] bigint  NOT NULL,
    [RecTime] datetime  NOT NULL,
    [Message] nvarchar(max)  NOT NULL,
    [Sender] bigint  NOT NULL,
    [ChatUsers_Id] bigint  NOT NULL
);
GO

-- Creating table 'ChatUsersSet'
CREATE TABLE [dbo].[ChatUsersSet] (
    [Id] bigint IDENTITY(1,1) NOT NULL,
    [Username] nvarchar(max)  NOT NULL,
    [AvatarID] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [RecTime], [Id] in table 'ChatDataSet'
ALTER TABLE [dbo].[ChatDataSet]
ADD CONSTRAINT [PK_ChatDataSet]
    PRIMARY KEY CLUSTERED ([RecTime], [Id] ASC);
GO

-- Creating primary key on [Id] in table 'ChatUsersSet'
ALTER TABLE [dbo].[ChatUsersSet]
ADD CONSTRAINT [PK_ChatUsersSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [ChatUsers_Id] in table 'ChatDataSet'
ALTER TABLE [dbo].[ChatDataSet]
ADD CONSTRAINT [FK_ChatUsersChatData]
    FOREIGN KEY ([ChatUsers_Id])
    REFERENCES [dbo].[ChatUsersSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_ChatUsersChatData'
CREATE INDEX [IX_FK_ChatUsersChatData]
ON [dbo].[ChatDataSet]
    ([ChatUsers_Id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------